#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 998244353
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n-1);
    for (int i = 0; i < n-1; i++)
    {
        cin>>v[i];
    }
    vector<vector<int>>graph(n+1);

    for (int i = 0; i < n-1; i++)
    {
        graph[i+2].push_back(v[i]);
        graph[v[i]].push_back(i+2);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<i<<" : ";
    //     for (int j = 0; j < graph[i].size(); j++)
    //     {
    //         cout<<graph[i][j]<<" ";
    //     }cout<<endl;
        
    // }
    

    queue<pair<int,int>> q;
    vector<bool> vis(n+1,false);
    q.push({1,0});
    vector<int> levels;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int node = it.first;
        int l = it.second;
        vis[node] = true;
        if(levels.size()<=l) levels.push_back(1);
        else levels[l]++;
        for(auto&i : graph[node]){
            if(!vis[i])
            q.push({i,l+1});
        }
    }   

    // for (int i = 0; i <levels.size(); i++)
    // {
    //     cout<<levels[i]<<" ";
    // }
    // cout<<endl;

    vector<int> ans(n+1, 0 );
    ans[1] = 1;
    queue<pair<int,pair<int,int>>> pq;
    pq.push({1,{0,-1}});
    fill(vis.begin(),vis.end(),false);
    vector<int> sum(levels.size(),0);
    sum[0] = 1;

    while(!pq.empty()){
        auto it = pq.front();
        pq.pop();
        int node = it.first;
        int l = it.second.first;
        int par = it.second.second;
        vis[node] = true;
        if(node!=1){
            ans[node] += (sum[l-1] - ans[par] + mod);
            sum[l] += ans[node];
            sum[l] %= mod;
            ans[node]%=mod;
        }
        for(auto&i : graph[node]){
            if(!vis[i]&&(levels[l]>1 || node == 1))
            pq.push({i,{l+1,node}});
            if(node==1) ans[i]++;
        }
    }   
    
    int ansct = 0;
    for (int i = 1; i <= n; i++)
    {
        ansct += ans[i];
        ansct %= mod;
    }
    cout<<ansct<<endl;
    
    
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
