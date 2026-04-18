#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>>edges;
    vector<vector<pair<int,int>>>v(n+1);
    
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==b) continue;
        else edges.push_back({min(a,b), max(a,b), c});      
    }

    sort(edges.begin(),edges.end());

    for (int i = 0; i < edges.size(); i++)
    {
        int w = edges[i][2];
        while(i+1<edges.size()&&edges[i][0]==edges[i+1][0]&&edges[i][1]==edges[i+1][1]){
            w = min(w,edges[i+1][2]);
            i++;
        }
        v[edges[i][0]].push_back({edges[i][1],w});
        v[edges[i][1]].push_back({edges[i][0],w});
    }

    vector<int> dist(n+1, 1e18), parent(n+1,-1);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,1});
    dist[1] = 0;
    while(!q.empty()){
        auto it = q.top();
        q.pop();
        int node = it.second;
        // cout<<node<<endl;
        int w = it.first;

        if(w>dist[node]) continue;

        for(auto&i:v[node]){
            if(w + i.second < dist[i.first]){
                parent[i.first] = node;
                dist[i.first] = w + i.second;
                q.push({w + i.second,i.first});
            }
        }
    }

    vector<int> ans;    
    if(parent[n]==-1){
        cout<<-1<<endl;
        return;
    }

    int par = n;
    while(par!=1){
        ans.push_back(parent[par]);
        par = parent[par];
    }
    for (int i = ans.size()-1; i >=0; i--)
    {
        cout<<ans[i]<<" ";
    }
    cout<<n<<endl;
    
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
