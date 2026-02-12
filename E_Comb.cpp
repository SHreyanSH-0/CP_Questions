#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    int ans = -1e8;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1e8)), sum(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a;
            cin>>a;
            sum[i][j] = a + sum[i][j-1];
            if(i==1)
            dp[i][j] = sum[i][j];
        }
    }
    for(int i=2;i<=n;i++){
        vector<int> v(m+1);
        if(i%2==1){
            int ml = -1e8;
            for(int j=1;j<=m;j++){
                v[j] = ml;
                ml = max(ml,dp[i-1][j]);
            }
        }
        else{
            int ml = -1e8;
            for(int j=m;j>=1;j--){
                v[j] = ml;
                ml = max(ml,dp[i-1][j]);
            }
        }
        for(int j=1;j<=m;j++){
            dp[i][j] = max(dp[i][j], sum[i][j] + v[j]);
            if(i==n) ans = max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
