#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define int long long

int dp[1000][2];

int rec(int n, int k, int d, int sum, int tight){
    if(sum>n){
        return 0;
    }
    if(sum==n){
        return (tight == 1);
    }

    if(dp[sum][tight]!=-1) return dp[sum][tight];

    int ans = 0;

    for(int i=1;i<=k;i++){
        ans += rec(n,k,d,sum+i,tight||(i>=d));
    }

    return dp[sum][tight] = ans%mod;
}

void solve()
{
    int n,k,d;
    cin>>n>>k>>d;
    cout<<rec(n,k,d,0,0);
}
signed main() {

    ll test=1;
//cin>>test;
    memset(dp,-1,sizeof(dp));
    while(test--)
    {
        solve();
    }
    return 0;
}
