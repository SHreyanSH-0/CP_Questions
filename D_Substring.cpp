#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; u++)
        for (int v : adj[u])
            indeg[v]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q.push(i);

    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cnt++;
        for (int v : adj[u]) {
            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    return cnt != n;
}

vector<int> dfs(vector<vector<int>> &v, int node,string &s,vector<vector<int>>& dp,vector<bool> &vis){
    if(v[node].size()==0){
        vector<int> hold(26,0);
        hold[s[node-1]-'a']++;
        return hold;
    }
    if(vis[node]){
        return dp[node];
    }
    vis[node] = true;
    vector<int> ans(26,0);
    for(int i=0;i<v[node].size();i++){
        vector<int> hold = dfs(v,v[node][i],s,dp,vis);
        
        for(int j=0;j<26;j++){
            ans[j] = max(ans[j],hold[j]);
        }
    }
    ans[s[node-1]-'a']++;
    return dp[node] = ans;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vector<int>> v(n+1);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    if(hasCycle(n+1,v)){
        cout<<-1;
        return;
    }
    vector<vector<int>> dp(n+1);
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++){
        dfs(v,i,s,dp,vis);
    }
    int ans = 0;
    for(int j = 1;j<=n;j++){
        for(int i=0;i<dp[j].size();i++){
            ans = max(ans,dp[j][i]);
        }
    }
    cout<<ans;
    
}
signed main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
