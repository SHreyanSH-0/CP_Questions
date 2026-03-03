#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(vector<vector<int>>&v,vector<vector<bool>>&vis, int i, int j){
    if(i<0||j<0||i>=v.size()||j>=v[0].size()) return 0;
    if(vis[i][j]) return 0;
    vis[i][j] = true;
    if (v[i][j]==0) return 0;
    
    
    return v[i][j] + rec(v,vis,i+1,j) + rec(v,vis,i-1,j) +rec(v,vis,i,j+1) + rec(v,vis,i,j-1); 
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<vector<int>> v(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>v[i][j];
        }   
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j]) ans = max(ans,rec(v,vis,i,j));
        }
        
    }
    cout<<ans<<endl;
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
