#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int dfs(vector<vector<int>> &v,int node, int par,int &ans, int k){
    if(v[node].size()==1&&par != -1) {
        return 1;
    }
    vector<int> ct;
    int ansIn = 1;
    for(auto &it : v[node]){
        if(it==par) continue;
        int hold = dfs(v,it,node,ans,k);
        ct.push_back(hold);
        ansIn += hold;
    }
    if(v.size()-1 - ansIn>0)
    ct.push_back(v.size()-1 - ansIn);
    for (int i = 0; i < ct.size(); i++)
    {
        if(v.size() - 1 - ct[i] - 1>=k-1) ans = ans + (ct[i]);
    }
    
    return ansIn;
}

void solve()
{
    int n, k;
    cin>>n>>k;
    
    vector<vector<int>> v(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = n;
    dfs(v,1,-1,ans,k);
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
