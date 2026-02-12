#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> level;
    queue<pair<int,int>> q;
    vector<int> vis(n+1,0);

    q.push({1,0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int node = it.first;
        int l = it.second;
        if(vis[node]==1) continue;
        vis[node] = 1;
        if(l>=level.size()) level.push_back(0);

        level[l]++;

        for(auto &it:v[node]) {
            if(vis[it]==1) continue;
            q.push({it,l+1});
        }

    }
    int ind ;
    int val = 0;
    int ct1 = -1;
    for (int i = 0; i < level.size(); i++)
    {
        if(val<level[i]){
            val = level[i];
            ct1 = 1;
        }
        else if(val==level[i]) ct1++;
    }
    int ct = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if(i==1){
            if(v[i].size()==val) {
                val++;
                break;
            }

        }
        else {
            if(v[i].size()-1==val){
                val++;
                break;
            }
        }
    }
    
    cout<<val<<endl;
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
