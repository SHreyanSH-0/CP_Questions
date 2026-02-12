#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> b(n+1);
    vector<vector<vector<int>>> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>b[i];
    }
    for (int i = 0; i < m; i++)
    {
        int s,t,w;
        cin>>s>>t>>w;
        v[s].push_back({t,w});
    }

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;

    q.push({0,{0,1}});

    vector<int> dist(n+1,INT_MAX);
    vector<int> s(n+1,INT_MIN);
    while(!q.empty()){
        auto it = q.top();
        q.pop();
        int node = it.second.second;
        int bat = it.first;
        int sum = it.second.first + b[node];
        if(node==n){
            cout<<bat<<endl;
            return;
        }
        if (sum < s[node]&&bat >= dist[node]) continue;
        dist[node] = bat;
        s[node] = max(sum,s[node]);
        for(auto &x : v[node]){
            if(sum>=x[1]){
                q.push({max(bat,x[1]),{sum,x[0]}});
            }
        }
    }
    
    cout<<-1<<endl;
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
