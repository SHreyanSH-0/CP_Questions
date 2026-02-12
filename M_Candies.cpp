#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    vector<int> sum(k+1);
    
    for (int i = 1; i <=n; i++)
    {
        sum[0] = dp[i-1][0];
        for (int j = 1; j <= k; j++)
        {
            sum[j] = (sum[j-1] + dp[i-1][j])%mod;
        }
        
        for (int j = 1; j <= k; j++)
        {
            int l = j - min(j,v[i]);
            if(l>0)
            dp[i][j] = (sum[j] - sum[l-1] + mod)%mod;
            else 
            dp[i][j] = sum[j];
        }
        
    }
    cout<<dp[n][k]<<endl;
    
    
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
