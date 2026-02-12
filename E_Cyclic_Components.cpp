#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int rec(vector<vector<int>>& graph, int node, int par, vector<bool>& vis){
    if(vis[node]){
        return 1;
    } 
    vis[node] = true;
    int ans = 0;
    for(int i=0;i<graph[node].size();i++){
        if(graph[node][i]!=par){
            ans += rec(graph,graph[node][i],node,vis);
        }
    }
    if(graph[node].size()>2) ans+= 10;
    return ans;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    
    for (int i = 0; i < m; i++)
    {
        int a , b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> vis(n+1,false);
    int ans = 0;    
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
            if(rec(graph,i,-1,vis)==2){
                ans++;
            } 
    }
    cout<<ans<<endl;
    
}
signed main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
