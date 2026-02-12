#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int ans = 0;
int rec(vector<vector<int>> &v, int node, int par){
    int hold = 1;
    for(int i=0;i<v[node].size();i++){
        if(v[node][i]!=par)
        hold += rec(v,v[node][i],node);
    }
    if(hold%2==0) ans++;
    return hold;

}

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n+1);
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(n%2==1) cout<<-1<<endl;
    else{
        rec(v,1,-1);
        cout<<ans-1<<endl;
    }
}
signed main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
