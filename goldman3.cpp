#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <algorithm>

using namespace std;

enum class JsonType { OBJECT, ARRAY, STRING, NUMBER, BOOLEAN, NULL_TYPE };

struct JsonValue {
    JsonType type;
    string stringVal;
    map<string, shared_ptr<JsonValue>> objectVal;
    vector<shared_ptr<JsonValue>> arrayVal;
};

struct MergedNode {
    bool hasString = false;
    bool hasNumber = false;
    bool hasBoolean = false;
    bool hasNull = false;

    bool hasObject = false;
    bool hasArray = false;

    int totalObjectInstances = 0;
    int keyPresenceCount = 0;
    bool isOptional = false;

    string assignedName;

    map<string, MergedNode> objectProps;
    unique_ptr<MergedNode> arrayElements;

    bool isEmpty() const {
        return !hasString && !hasNumber && !hasBoolean && !hasNull && !hasObject && !hasArray;
    }
};

class Solution {
    string rootName;
    string jsonText;
    set<string> usedNames;
    map<string, string> outputInterfaces;
    MergedNode rootNode;

    void skipWhitespace(int& pos) {
        while (pos < jsonText.size() && isspace(jsonText[pos])) {
            pos++;
        }
    }

    shared_ptr<JsonValue> parseString(int& pos) {
        auto node = make_shared<JsonValue>();
        node->type = JsonType::STRING;
        pos++; 
        string res;
        while (pos < jsonText.size()) {
            if (jsonText[pos] == '\\') {
                pos += 2; 
            } else if (jsonText[pos] == '"') {
                pos++;
                break;
            } else {
                res += jsonText[pos];
                pos++;
            }
        }
        node->stringVal = res;
        return node;
    }

    shared_ptr<JsonValue> parseNumber(int& pos) {
        auto node = make_shared<JsonValue>();
        node->type = JsonType::NUMBER;
        while (pos < jsonText.size() && (isdigit(jsonText[pos]) || jsonText[pos] == '-' || 
               jsonText[pos] == '.' || jsonText[pos] == 'e' || jsonText[pos] == 'E' || jsonText[pos] == '+')) {
            pos++;
        }
        return node;
    }

    shared_ptr<JsonValue> parseLiteral(int& pos) {
        auto node = make_shared<JsonValue>();
        if (jsonText.substr(pos, 4) == "true") {
            node->type = JsonType::BOOLEAN;
            pos += 4;
        } else if (jsonText.substr(pos, 5) == "false") {
            node->type = JsonType::BOOLEAN;
            pos += 5;
        } else if (jsonText.substr(pos, 4) == "null") {
            node->type = JsonType::NULL_TYPE;
            pos += 4;
        }
        return node;
    }

    shared_ptr<JsonValue> parseArray(int& pos) {
        auto node = make_shared<JsonValue>();
        node->type = JsonType::ARRAY;
        pos++; 
        skipWhitespace(pos);
        if (pos < jsonText.size() && jsonText[pos] == ']') {
            pos++;
            return node;
        }
        while (pos < jsonText.size()) {
            skipWhitespace(pos);
            node->arrayVal.push_back(parseValue(pos));
            skipWhitespace(pos);
            if (jsonText[pos] == ']') {
                pos++;
                break;
            }
            pos++; 
        }
        return node;
    }

    shared_ptr<JsonValue> parseObject(int& pos) {
        auto node = make_shared<JsonValue>();
        node->type = JsonType::OBJECT;
        pos++; 
        skipWhitespace(pos);
        if (pos < jsonText.size() && jsonText[pos] == '}') {
            pos++;
            return node;
        }
        while (pos < jsonText.size()) {
            skipWhitespace(pos);
            auto keyNode = parseString(pos);
            skipWhitespace(pos);
            pos++; 
            skipWhitespace(pos);
            auto valNode = parseValue(pos);
            node->objectVal[keyNode->stringVal] = valNode;
            skipWhitespace(pos);
            if (jsonText[pos] == '}') {
                pos++;
                break;
            }
            pos++; 
        }
        return node;
    }

    shared_ptr<JsonValue> parseValue(int& pos) {
        skipWhitespace(pos);
        if (pos >= jsonText.size()) return nullptr;
        char c = jsonText[pos];
        if (c == '{') return parseObject(pos);
        if (c == '[') return parseArray(pos);
        if (c == '"') return parseString(pos);
        if (c == 't' || c == 'f' || c == 'n') return parseLiteral(pos);
        return parseNumber(pos);
    }

    void mergeValue(shared_ptr<JsonValue> val, MergedNode& target) {
        if (!val) return;
        if (val->type == JsonType::NULL_TYPE) target.hasNull = true;
        else if (val->type == JsonType::BOOLEAN) target.hasBoolean = true;
        else if (val->type == JsonType::NUMBER) target.hasNumber = true;
        else if (val->type == JsonType::STRING) target.hasString = true;
        else if (val->type == JsonType::OBJECT) {
            target.hasObject = true;
            target.totalObjectInstances++;
            for (auto& pair : val->objectVal) {
                target.objectProps[pair.first].keyPresenceCount++;
                mergeValue(pair.second, target.objectProps[pair.first]);
            }
        }
        else if (val->type == JsonType::ARRAY) {
            target.hasArray = true;
            if (!target.arrayElements) {
                target.arrayElements = make_unique<MergedNode>();
            }
            for (auto& elem : val->arrayVal) {
                if (elem->type == JsonType::OBJECT) {
                    target.arrayElements->hasObject = true;
                    target.arrayElements->totalObjectInstances++;
                    for (auto& pair : elem->objectVal) {
                        target.arrayElements->objectProps[pair.first].keyPresenceCount++;
                        mergeValue(pair.second, target.arrayElements->objectProps[pair.first]);
                    }
                } else {
                    mergeValue(elem, *target.arrayElements);
                }
            }
        }
    }

    void finalizeOptionals(MergedNode& node) {
        for (auto& pair : node.objectProps) {
            if (pair.second.keyPresenceCount < node.totalObjectInstances) {
                pair.second.isOptional = true;
            }
            finalizeOptionals(pair.second);
        }
        if (node.hasArray && node.arrayElements) {
            finalizeOptionals(*node.arrayElements);
        }
    }

    void assignNames(MergedNode& node) {
        for (auto& pair : node.objectProps) {
            const string& key = pair.first;
            MergedNode& child = pair.second;

            if (child.hasObject) {
                string base = string(1, toupper(key[0])) + key.substr(1);
                string name = base;
                int suffix = 2;
                while (usedNames.count(name)) {
                    name = base + to_string(suffix++);
                }
                usedNames.insert(name);
                child.assignedName = name;
                assignNames(child);
            } else if (child.hasArray && child.arrayElements && child.arrayElements->hasObject) {
                string base = string(1, toupper(key[0])) + key.substr(1);
                string name = base;
                int suffix = 2;
                while (usedNames.count(name)) {
                    name = base + to_string(suffix++);
                }
                usedNames.insert(name);
                child.arrayElements->assignedName = name;
                assignNames(*child.arrayElements);
            }
        }
    }

    string getTypeString(const MergedNode& node) {
        vector<string> types;
        if (node.hasNull) types.push_back("null");
        if (node.hasBoolean) types.push_back("boolean");
        if (node.hasNumber) types.push_back("number");
        if (node.hasString) types.push_back("string");
        if (node.hasObject) types.push_back(node.assignedName);
        if (node.hasArray) {
            if (!node.arrayElements || node.arrayElements->isEmpty()) {
                types.push_back("unknown[]");
            } else {
                string elemType = getTypeString(*node.arrayElements);
                if (elemType.find('|') != string::npos) {
                    types.push_back("(" + elemType + ")[]");
                } else {
                    types.push_back(elemType + "[]");
                }
            }
        }

        if (types.empty()) return "unknown"; 

        sort(types.begin(), types.end());
        string res = types[0];
        for (size_t i = 1; i < types.size(); i++) {
            res += " | " + types[i];
        }
        return res;
    }

    void generateInterfaces(const MergedNode& node) {
        if (!node.assignedName.empty() && node.hasObject) {
            string s;
            if (node.objectProps.empty()) {
                s = "export interface " + node.assignedName + " {}";
            } else {
                s = "export interface " + node.assignedName + " {\n";
                for (auto& pair : node.objectProps) {
                    s += "  " + pair.first;
                    if (pair.second.isOptional) s += "?";
                    s += ": " + getTypeString(pair.second) + ";\n";
                }
                s += "}";
            }
            outputInterfaces[node.assignedName] = s;
        }

        for (auto& pair : node.objectProps) {
            generateInterfaces(pair.second);
        }
        if (node.hasArray && node.arrayElements) {
            generateInterfaces(*node.arrayElements);
        }
    }

public:
    Solution(const string& rootName, const string& jsonText) : rootName(rootName), jsonText(jsonText) {}

    string solve() {
        int pos = 0;
        auto rootJson = parseArray(pos);
        if (!rootJson) return ""; 

        rootNode.hasObject = true;
        for (auto& elem : rootJson->arrayVal) {
            if (elem && elem->type == JsonType::OBJECT) {
                rootNode.totalObjectInstances++;
                for (auto& pair : elem->objectVal) {
                    rootNode.objectProps[pair.first].keyPresenceCount++;
                    mergeValue(pair.second, rootNode.objectProps[pair.first]);
                }
            }
        }

        finalizeOptionals(rootNode);

        usedNames.insert(rootName);
        rootNode.assignedName = rootName;
        assignNames(rootNode);

        generateInterfaces(rootNode);

        string tcOut;
        bool first = true;
        for (auto& pair : outputInterfaces) {
            if (!first) tcOut += "\n\n";
            tcOut += pair.second;
            first = false;
        }
        return tcOut;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    if (!getline(cin, line)) return 0;
    
    int t = 0;
    try {
        t = stoi(line);
    } catch (...) {
        return 0;
    }

    string out;
    for (int i = 0; i < t; i++) {
        string rootName, jsonText;
        getline(cin, rootName);
        getline(cin, jsonText);

        if (i > 0) out += "\n---\n";
        
        Solution sol(rootName, jsonText);
        out += sol.solve();
    }

    out += '\n';
    cout << out;

    return 0;
}