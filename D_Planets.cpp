#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> v(n+1);
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    vector<vector<int>> travel(n+1);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin>>a;
        vector<int> hold(a);
        for (int j = 0; j < a; j++)
        {
            int b;
            cin>>b;
            travel[i].push_back(b);
        }
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n+1,1e15);
    dist[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int currTime = it.first;
        if(node==n) {
            cout<<currTime<<endl;
            return;
        }
        if(dist[node]<currTime) continue;
        int low = 0, high = 1e15;
        vector<int> &hold = travel[node]; 
        int ans=0;
        int idx = lower_bound(hold.begin(),hold.end(),currTime) - hold.begin();
        if(idx<hold.size()&&hold[idx]==currTime){
            for(idx;idx<hold.size();idx++){
                if(hold[idx]==currTime) currTime++;
                else break;
            }
        }
        currTime = currTime + ans;

        for(auto &[x,t] : v[node]){
            // cout<<node<<" "<<x<<","<<t<<endl;
            if(dist[x]>currTime + t){
                dist[x] = currTime + t;
                pq.push({dist[x],x});
            }
        }
    }
    if(dist[n]==1e15) cout<<-1<<endl;
    else cout<<dist[n]<<endl;
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
