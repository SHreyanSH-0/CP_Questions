#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int a,b,c,m;
    cin>>a>>b>>c>>m;

    int g = __gcd(a,b);
    int hold = (a/g)*b;
    g = __gcd(hold,c);
    
    int abc = (m/(hold*(c/g)));
    g = __gcd(a,b);
    int ab = (m/((a/g)*b) - abc);
    g = __gcd(a,c);
    int ac = (m/((a/g)*c) - abc);
    g = __gcd(c,b);
    int cb = (m/((c/g)*b) - abc);
    a = (m/a - ab - ac - abc)*6 + (ab + ac)*3 + abc * 2;
    b = (m/b - ab - cb - abc)*6 + (ab + cb)*3 + abc * 2;
    c = (m/c - ac - cb - abc)*6 + (ac + cb)*3 + abc * 2;

    cout<<a<<" "<<b<<" "<<c<<endl;
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
