#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    vector<bool> dp(n+1,false);
    dp[0] = true;
    set<int> s,s2;
    s.insert(v[0]);
    
    for (int i = 2; i <= n; i++)
    {
        if(s.find(i-1)!=s.end()||v[i-1]==i-1||s2.find(i-1-v[i-1])!=s2.end()) dp[i] = true;
        if(i<n&&dp[i]){
            s.insert(v[i] + i);
            s2.insert(i);
        } 
    }
    
    if(dp[n]) cout<<"YES\n";
    else cout<<"NO\n";
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
