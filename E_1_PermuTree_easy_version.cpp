#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int finalans = 0;

int rec(vector<int>&v,int i,int sum , int total,vector<vector<int>>&dp){
    if(i>=v.size()) return sum*(total-sum);
    if(dp[i][sum]!=-1) return dp[i][sum];
    int p = rec(v,i+1,sum+v[i],total,dp);
    int np = rec(v,i+1,sum,total,dp);
    return dp[i][sum] = max(p,np);
}

int dfs(vector<vector<int>> &graph, int node , vector<bool>&vis){
    if(vis[node]) return 0;
    vis[node] = true;
    vector<int> hold;
    int ans = 1;
    for(auto it : graph[node]){
        if(!vis[it]){
            int a = dfs(graph,it,vis);
            hold.push_back(a);
            ans += a;
        }
    }
    vector<vector<int>>dp(hold.size(),vector<int>(ans,-1));
    int b = rec(hold,0,0,ans-1,dp);
    finalans += b;
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1);
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin>>a;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }   
    vector<bool> vis(n+1,false);
    dfs(graph,1,vis);
    cout<<finalans<<endl;
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
    
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
