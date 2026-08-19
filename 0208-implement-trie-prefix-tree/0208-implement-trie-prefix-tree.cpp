class Trie {
    struct Node {
        Node* child[26];
        bool isEnd;
    
        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };
    
    Node* root;
    
  public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        
        int n = word.size();
        
        for(int i=0;i<n;i++){
            if(node->child[word[i]-'a'] != NULL){
                node = node->child[word[i]-'a'];
            }
            else{
                node->child[word[i]-'a'] = new Node();
                node = node->child[word[i]-'a'];
            }
        }
        
        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = root;
        
        int n = word.size();
        
        for(int i=0;i<n;i++){
            if(node->child[word[i]-'a'] != NULL){
                node = node->child[word[i]-'a'];
            }
            else{
                return false;
            }
            
        }
        return node->isEnd; 
    }

    bool startsWith(string word) {
        Node* node = root;
        
        int n = word.size();
        
        for(int i=0;i<n;i++){
            if(node->child[word[i]-'a'] != NULL){
                node = node->child[word[i]-'a'];
            }
            else{
                return false;
            }
            
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */