class Solution {
public:
    int rec(string &s, string &t,vector<vector<int>> &dp,int i,int j){
        if(j==t.size()) return 1;
        else if(i==s.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = rec(s,t,dp,i+1,j+1)+rec(s,t,dp,i+1,j);
        }
        return dp[i][j] = rec(s,t,dp,i+1,j);
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return rec(s,t,dp,0,0);
    }
};