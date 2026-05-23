#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    int ans = 0;
    vector<int> dp(n+1,0);
    dp[0] = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if(a[i-1]==b[i-1]){
            if(a[i-1]==1){
                sum = sum  + 1;
                dp[1] += dp[0] + 1;
                dp[0] = 0;
            }
            else{
                sum = sum + 1; 
                dp[a[i-1]] += dp[a[i-1] -1];  
                dp[a[i-1] -1] = 0;
                dp[0]++;
            }
        }
        else{
            if(a[i-1]==1||b[i-1]==1){
                sum = sum - dp[0];
                dp[0]=0;
                sum = sum - dp[a[i-1]-1];
                dp[a[i-1]-1] = 0;
                sum = sum - dp[b[i-1]-1];
                dp[b[i-1]-1] = 0;
            }
            else{
                sum = sum -dp[a[i-1] -1] -dp[b[i-1]-1] + 1;
                dp[0]++;
                dp[a[i-1]-1] = 0;
                dp[b[i-1]-1] = 0;
            }
        }
        
        ans += sum;
    }
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
