#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int dfs(vector<int> &v,vector<vector<int>> &graph,int m,int consi,int maxConsi,int node,int par){
    if(graph[node].size()==1&&graph[node][0]==par) return (v[node]==1?max(maxConsi,consi+1):maxConsi)<=m;

    int ans = 0;
    for(int i = 0;i<graph[node].size();i++){
        if(graph[node][i] == par) continue;
        ans += dfs(v,graph,m,v[node]==1?consi+1:0,v[node]==1?max(maxConsi,consi+1):maxConsi ,graph[node][i],node);
    }
    return ans;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    
    vector<int> v(n+1);

    vector<vector<int>> graph(n+1);

    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }
    for (int i = 1; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout<<dfs(v,graph,m,0,0,1,-1)<<endl;
    
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
