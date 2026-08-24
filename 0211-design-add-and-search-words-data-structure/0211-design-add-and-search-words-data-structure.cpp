class WordDictionary {

    struct Node{
        Node* children[26];
        bool isEnd = false;

        Node(){
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
        }
    };

    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;

        int n = word.size();

        for(int i=0;i<n;i++){
            if(node->children[word[i]-'a'] == nullptr){
                node->children[word[i]-'a'] = new Node();
            }
            node = node->children[word[i]-'a'];
        }

        node->isEnd = true;
    }

    // vector<string> gen_words(string &word){
    //     vector<string> words_comb;
    //     vector<int> ind;
    //     for(int i=0;i<word.size();i++){
    //         if(word[i] == '.') ind.push_back(i);
    //     }
    //     if(ind.size() == 0) return {word};

    //     if(ind.size() == 1){
    //         string temp = word;
    //         for(char c='a';c<='z';c++){
    //             temp[ind[0]] = c;
    //             words_comb.push_back(temp);
    //         }
    //     }

    //     if(ind.size() == 2){
    //         string temp = word;
    //         for(char c='a';c<='z';c++){
    //             for(char d ='a';d<='z';d++){
    //                 temp[ind[0]] = c;
    //                 temp[ind[1]] = d;
    //                 words_comb.push_back(temp);
    //             }
    //         }
    //     }

    //     return words_comb;

    // }

    bool find_word(string &word, int i, Node* node){
        if(i >= word.size()) return node->isEnd;
        bool ans = false;
        if(word[i] == '.'){
            for(int j=0;j<26;j++){
                if(node->children[j] != nullptr){
                    ans = ans | find_word(word,i+1,node->children[j]);
                }
            }
        }
        else{
            if(node->children[word[i]-'a'] == nullptr) return false;
            ans = find_word(word,i+1,node->children[word[i] - 'a']);
        }
        return ans;
    }
    
    bool search(string word) {
        bool ans = false;

        // vector<string> words_comb = gen_words(word);
        Node* node = root;
        ans = find_word(word,0,root);
        

        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */