#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(k==v[i]) check = true;
    }
    sort(v.begin(),v.end());
    int g=0;
    for (int i=1;i<n;++i){
        g=__gcd(g,v[i]-v[0]);
    }
    if ((k-v[0])%g) cout<<"NO\n";
    else cout<<"YES\n";
    
    
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
