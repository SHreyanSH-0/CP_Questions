#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

class dsu{
    public:
    vector<int> parent, size;
    dsu(int n){
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int up(int a){
        if(parent[a]!=a) parent[a] = up(parent[a]);
        return parent[a];
    }

    void unite(int a, int b){
        int para = up(a);
        int parb = up(b);
        if(para == parb) return;
        if(size[para]>=size[parb]){
            parent[parb] = para;
            size[para] += size[parb];
        }
        else{
            parent[para] = parb;
            size[parb] += size[para];
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n), c(n), k(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    
    vector<bool> vis(n,false);
    
    dsu d(n);

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    
    for(int i=0;i<n;i++){
        pq.push({c[i],{i,i}});
        for(int j=i+1;j<n;j++){
            pq.push({(abs(x[i] - x[j]) + abs(y[i] - y[j]))*(k[i] + k[j]), {i,j}});
        }
    }
    int ans = 0;
    vector<pair<int,int>> conn;
    vector<int> t;
    int ct = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int cost = it.first;
        int a = it.second.first;
        int b = it.second.second;

        if(a==b){
            int para = d.up(a);
            if(!vis[para]){
                ans += cost;
                vis[a] = true;
                vis[para] = true;
                t.push_back(a);
            }
        }
        else {
            int para = d.up(a);
            int parb = d.up(b);
            if(para==parb) continue;
            if(vis[para]&&vis[parb]){
                vis[a] = true;
                vis[b] = true;
            }
            else if(vis[para]||vis[parb]){
                ans += cost;
                conn.push_back({a,b});
                d.unite(para,parb);
                vis[a] = true;
                vis[b] = true;
                vis[para] = true;
                vis[parb] = true;
            }
            else {
                conn.push_back({a,b});
                d.unite(para,parb);
                ans += cost;
            }
        }
    }

    cout<<ans<<endl;
    cout<<t.size()<<endl;
    for(int i=0;i<t.size();i++){
        cout<<t[i] + 1<<" ";
    }cout<<endl;
    cout<<conn.size()<<endl;
    for (int i = 0; i < conn.size(); i++)
    {
        cout<<conn[i].first + 1<<" "<<conn[i].second + 1<<endl;
    }

    

}
signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
