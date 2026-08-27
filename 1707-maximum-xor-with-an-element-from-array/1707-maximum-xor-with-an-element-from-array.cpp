struct Node{
    Node* children[2];
    bool isEnd = false;

    Node(){
        for(int i=0;i<2;i++) children[i] = nullptr;
    }
};

class trie{
    public:
    Node* root;

    trie(){
        root = new Node();
    }

    
    void insert(string&num){
        int n = num.size();
        Node* node = root;
        for(int i=0;i<n;i++){
            if(node->children[num[i]-'0'] == nullptr) node->children[num[i]-'0'] = new Node();
            node = node->children[num[i]-'0'];
        }
        node->isEnd = true;
    }

    string search(string&num){
        int n = num.size();
        Node* node = root;
        string ans = "";
        for(int i=0;i<n;i++){
            if(node->children[num[i]-'0'] == nullptr){
                if(node->children[!(num[i]-'0')] != nullptr) node = node->children[!(num[i]-'0')], ans.push_back(!(num[i]-'0') + '0');
                else break;
            }
            else{
                node = node->children[num[i]-'0'];
                ans.push_back(num[i]);
            }
        }

        if(ans.size() != 32) return "";
        return ans;
    }   
};

class Solution {
public:

    static bool comp(vector<int>&a,vector<int>b){
        return a[1] < b[1];
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        trie t;
        
        int n = nums.size();
        int m = q.size();
        vector<int> ans(m);

        for(int i=0;i<m;i++) q[i].push_back(i);

        sort(nums.begin(),nums.end());
        sort(q.begin(),q.end(),comp);
        int j = 0;

        for(int i=0;i<m;i++){
            while(j<n && nums[j] <= q[i][1]){
                string num = "";

                int hold = nums[j];
                cout<<hold<<endl;
                while(hold>0){
                    num.push_back(hold%2 + '0');
                    hold/=2;
                }

                while(num.size() < 32) num.push_back('0');
                reverse(num.begin(),num.end());
                t.insert(num);
                j++;
            }

            int x = q[i][0];

            string num = "";
            int hold = x;

            while(hold>0){
                num.push_back(hold%2 + '0');
                hold/=2;
            }

            while(num.size() < 32) num.push_back('0');

            reverse(num.begin(),num.end());
            string c = "";

            for(int j=0;j<num.size();j++){
                if(num[j] == '1') c.push_back('0');
                else c.push_back('1');
            }

            string s = t.search(c);

            // cout<<num<<endl<<c<<endl<<s<<endl<<endl;
            if(s == "") {ans[q[i][2]] = -1; continue;}
            long long ct = 0;
            long long p = 1;
            for(int j=31;j>=0;j--){
                if(num[j] != s[j]) ct+=p;
                p*=2;
            }
            ans[q[i][2]] = ct;
        }

        return ans;
    }
};