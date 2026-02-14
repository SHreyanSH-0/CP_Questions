#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int md = -1,d1 = 1;
void rec(vector<vector<int>> &v, int node, vector<bool> &vis, int d,int par){
    if(v[node].size()==1&&v[node][0]==par){
        if(d>md){
            d1 = node;
            md = d;
        }
        return;
    }
    if(vis[node]) return;
    vis[node] = true;
    for(auto &it : v[node]){
        if(it==par) continue;
        rec(v,it,vis,d+1,node);
    }
}

vector<int> bfs(vector<vector<int>> &v, int dia){
    queue<pair<int,int>> q;
    q.push({dia,0});
    vector<int> dist(v.size()+1,0);
    vector<bool> vis(v.size() + 1, false);
    while(!q.empty()){
        int node = q.front().first;
        int d = q.front().second;
        q.pop();
        vis[node] = true;
        dist[node] = d;
        for(auto &it : v[node]){
            if(!vis[it]){
                q.push({it,d+1});
            }
        }
    }
    return dist;
}

void solve()
{
    int n,k,c;
    cin>>n>>k>>c;
    vector<vector<int>> v(n+1);
    md = -1, d1 = 1;
    for (int i = 0; i < n-1; i++)
    {
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> vis(n+1,false), vis2(n+1,false);
    rec(v,1,vis,0,-1);
    int dia1 = d1;
    md = -1;
    d1 = 1;
    rec(v,dia1,vis2,0,-1);
    int dia2 = d1;

    vector<int> dist1 = bfs(v,dia1), dist2 = bfs(v,dia2), dist3 = bfs(v,1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans,max(dist1[i],dist2[i])*k - dist3[i]*c);
        // cout<<dist1[i]<<" "<<dist2[i]<<" "<<dist3[i]<<endl;
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
