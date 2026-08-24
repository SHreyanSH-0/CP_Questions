struct Node{
    Node* children[26];
    bool isEnd = false;
    Node(){
        for(int i=0;i<26;i++) children[i] = NULL;
    }
};
class trie{
    public:

    Node* root;

    trie(){
        root = new Node();
    }

    void insert(string&word){
        int n = word.size();
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->children[word[i]-'a'] == NULL){
                node->children[word[i]-'a'] = new Node();
            }
            node = node->children[word[i]-'a'];
        }
        node->isEnd = true;
    }

    bool search(string&word){
        int n = word.size();
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->children[word[i]-'a'] == NULL){
                return false;
            }
            node = node->children[word[i]-'a'];
        }

        return true;
    }
};


class Solution {
public:

    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};

    void rec(vector<vector<char>>& board,vector<vector<bool>>& vis,set<string>&hold, string &s, int i, int j,int n, Node* node){
        
        bool check = false;
        for(int idx=0;idx<4;idx++){
            int r = i + x[idx];
            int c = j + y[idx];

            if(r>=0 && c>=0 && r < board.size() && c < board[0].size() && !vis[r][c] && node->children[board[r][c]-'a'] != nullptr){
                s.push_back(board[r][c]);
                vis[r][c] = true;
                rec(board,vis,hold,s,r,c,n,node->children[board[r][c]-'a']);
                vis[r][c] = false;
                s.pop_back();
                check = true;
            }
        }

        if(node->isEnd) hold.insert(s);
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int n = board.size();
        int m = board[0].size();

        trie t;
        for(int i = 0; i < words.size(); i++) {
            t.insert(words[i]);
        }

        set<string> hold;
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        Node* node = t.root;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(node->children[board[i][j]-'a']!= nullptr){
                    string s;
                    s.push_back(board[i][j]);
                    vis[i][j] = true;
                    rec(board,vis,hold,s,i,j,10,node->children[board[i][j]-'a']);
                    vis[i][j] = false;
                }
            }
        }
        
        for(auto&s : hold) ans.push_back(s);
        


        return ans;
    }
};