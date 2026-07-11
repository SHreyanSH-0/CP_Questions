#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void solve()
{
    int t,k;
    cin>>t>>k;

    vector<int> dp(1e5+1,0);
    dp[0] = 1;

    for (int i = 1; i <= 1e5; i++)
    {
        dp[i] = (dp[i-1] + (i-k>=0? dp[i-k]:0))%mod;
    } 

    vector<int> pref(1e5+1);

    pref[0] = 0;

    for (int i = 1; i <= 1e5; i++)
    {
        pref[i] = (pref[i-1] + dp[i])%mod;
    }
    
    


    for (int i = 0; i < t; i++)
    {
        int a,b;
        cin>>a>>b;

        cout<<(pref[b] - pref[a-1] + mod)%mod<<endl;
    }
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
    while(test--)
    {
        solve();
    }
    return 0;
}
