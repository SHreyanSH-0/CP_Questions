#include<bits/stdc++.h>
#define int long long
using namespace std;
int dfs(vector<vector<int>>&adj,vector<int>&v,int node,int b){
    v[node]=1;
    int ans=1;
    for(auto &x:adj[node]){
        if(x==b || v[x]==1)continue;
        ans+=dfs(adj,v,x,b);
    }
    return ans;
}

void solve(){

    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>v1(n+1,0);
    vector<int>v2(n+1,0);
    int one=n-dfs(adj,v1,a,b)-1;
    int two=n-dfs(adj,v2,b,a)-1;
    cout<<one*two;




}
signed main(){
    int _=1;
    cin>>_;
    while(_--){
        solve();
        cout<<"\n";
    }
}