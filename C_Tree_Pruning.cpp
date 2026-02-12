#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(vector<vector<int>> &v, int node, int par, int depth, vector<int> &d){
    if(v[node].size()==1&&par) return d[node] = depth;
    for(auto &it:v[node]){
        if(it==par) continue;
        d[node] = max(d[node],rec(v,it,node,depth+1,d));
    }
    return d[node];
}

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n+1);
    vector<int> d(n+1,0);

    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    rec(v,1,-1,0,d);
    vector<int> level, vis(n+1, 0);
    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()){
        int node = q.front().first;
        int l = q.front().second;
        q.pop();

        if(vis[node]) continue;
        vis[node] = 1;
        if(l>=level.size()) level.push_back(0);
        level[l]++;
        for(auto &it:v[node]){
            if(vis[it]==1) continue;
            q.push({it,l+1});
        }
    }

    sort(d.begin(),d.end());
    int limit = d[d.size()-1];
    int ans = n;
    vector<int> sum(limit+1);
    sum[0] = 0;

    for(int i=1;i<level.size();i++){
        sum[i] = sum[i-1] + level[i];
    }

    for(int i=0;i<=limit;i++){
        int ind = lower_bound(d.begin()+1, d.end(), i) - d.begin();
        int s = sum[limit] - sum[i];
        ans = min(ans,ind - 1 + s);
    }
    cout<<ans<<endl;
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
