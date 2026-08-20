class Solution {
public:
    int dp[100001][30];

    int rec(vector<vector<int>>& v,vector<int>&coins, int node , int op,int par, int k){
        if(op > 14) return 0;

        if(dp[node][op]!=-1) return dp[node][op];
        int ans1= (coins[node]/(1<<op)) - k;
        int ans2= (coins[node]/(1<<(op + 1)));
        for(auto&it : v[node]){
            if(it == par) continue;
            ans1 += rec(v,coins,it,op,node,k);
            ans2 += rec(v,coins,it,op+1,node,k);
        }
        return dp[node][op] = max(ans1,ans2);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        vector<vector<int>> v(coins.size());

        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        memset(dp,-1,sizeof(dp));
        return rec(v,coins,0,0,-1,k);
    }
};