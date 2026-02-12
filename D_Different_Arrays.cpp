#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 998244353
int dp[300][2*90001];
int rec(vector<int>&v, int i){
    if(i>=v.size()-1) return 1;
    if(dp[i][v[i] + 90000]!=-1) return dp[i][v[i]+ 90000];
    int hold = v[i+1];
    int ans = 0;
    if(v[i]==0)  {
        ans = rec(v,i+1);
    }
    else{
        v[i+1] = hold + v[i];
        ans += rec(v,i+1);
        ans%=mod;
        v[i+1] = hold - v[i];
        ans += rec(v,i+1);
        ans%=mod;
    }
    v[i+1] = hold;
    ans%=mod;
    return dp[i][v[i]+ 90000] = ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    cout<<rec(v,1);
}
signed main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
