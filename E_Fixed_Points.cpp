#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    dp[0][0] = 0;
    dp[1][0] = 0;
    int ct = 0;
    for(int i=1;i<=n;i++){
        if(v[i-1]==i) ct++;

        dp[0][i] = ct;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int c = 0;
            if((v[j-1]== j - i)) c = 1;
            dp[i][j] = max( c + dp[i][j-1] , dp[i-1][j-1]);
            dp[i][j] = max(dp[i][j],0LL);
        }
    }
    int ans = -1;
    for (int i = 0; i <= n&&ans==-1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dp[i][j]>=k) {
                ans = i;
                break;
            }
        }
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
