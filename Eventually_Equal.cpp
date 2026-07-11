#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;

    // max ans = 3

    if(a==b) cout<<0<<endl;
    else{
        if(__gcd(a,c) == __gcd(b,c)) cout<<1<<endl;
        else if(__gcd(a,c+1) == __gcd(b,c+1)) cout<<2<<endl;
        else cout<<3<<endl;
    }
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
