#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int o = 0, z = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1') o++;
        else z++;
        if(o>z) ans++;
        
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
