#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;
    int g = __gcd(a,b);
    int hold = (a/g)*b;
    int red = n/a;
    int blue = n/b;
    int both = n/hold;
    int ans = 0;
    if(p>q){
        ans = p*red + (blue-both)*q;
    }
    else{
        ans = (red-both)*p + blue*q;
    }
    cout<<ans;

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
