#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    double n,x,y,z;
    cin>>n>>x>>y>>z;
    double ans = 1e15;
    // donot ai
    ans = ceil(n/(x+y));
    //ai
    if(ceil(n/x)<=z){
        ans = min(ans,ceil(n/x));
    }
    else ans = min(ans,z + ceil((n - x*z)/(x + 10*y)));
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
