class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> v(26);
        string ans = "";
        
        int n = s.size();
        
        for(int i=0;i<n;i++){
            if(s[i] == '*'){
                for(int j=0;j<26;j++){
                    if(!v[j].empty()){
                        v[j].pop();
                        break;
                    }
                }
            }
            else{
                v[s[i] - 'a'].push(i);
            }
        }

        vector<int> hold;

        for(int i=0;i<26;i++){
            while(!v[i].empty()) {
                hold.push_back(v[i].top());
                v[i].pop();
            }
        }

        sort(hold.begin(),hold.end());

        for(int i=0;i<hold.size();i++) ans.push_back(s[hold[i]]);
        
        return ans;
    }
};