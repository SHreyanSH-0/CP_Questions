#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

struct DSU {
    vector<int> parent;
    vector<int> sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    // Find with path compression
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    
    // Union by size
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
        }
    }
    
    int get_size(int i) {
        return sz[find(i)];
    }
};


void solve()
{
    int n,m;
    cin>>n>>m;
    int dd = log2(n) + 1;
    vector<int> v(((10LL << dd) | (n+1)),-1);
    DSU ds(n+1);
    DSU ds2(((10LL << dd) | (n+1)));
    vector<vector<int>> hold;
    for (int j = 0; j < m; j++)
    {
        int a,d,k;
        cin>>a>>d>>k;
        hold.push_back({a,d,k});
    }
    sort(hold.begin(),hold.end());
    for (int j = 0; j < m; j++)
    {
        int a = hold[j][0],d= hold[j][1],k = hold[j][2];
        int start = a;
        int end = min(n,a + d*k);
        if(v[ds2.find((d<<dd) | start)] != -1) start = v[ds2.find((d<<dd) | start)];
        if(start >= end ) continue;
        for (int i = start ; i <= end && i <= n; i+=d)
        {
            if(v[ds2.find((d<<dd) | start)] >= end){
                ds.unite(start, i);
                break;
            } 
            int a1 = v[ds2.find((d<<dd) | start)];
            ds.unite(start, i);
            ds2.unite(((d<<dd) | start), ((d<<dd) | i));
            // cout<<i<<" ";
            v[ds2.find((d<<dd) | i)] = max(max(a1,i),v[ds2.find((d<<dd) | i)]);
        }
    }
    set<int> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.insert(ds.find(i));
    }

    cout<<ans.size()<<endl;
    
    
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
