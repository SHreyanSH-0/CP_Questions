#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int dp[21][1002];
int rec(int n, int m, int i, int prev,int last){
    if(i>=2*m) {
        return 1;
    }
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int ans = 0;
    for(int ind=1;ind<=n;ind++){
        if(prev<=ind)
            ans = (ans +  rec(n,m,i+1,ind,ind))%mod;
        
    }
    return dp[i][prev+1] = ans;
}

void solve()
{
    int n, m;
    cin>>n>>m;
    long long ans = 0;
    memset(dp,-1,sizeof(dp));
    cout<<rec(n,m,0,-1,-1);
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
