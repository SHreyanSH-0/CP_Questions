#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int ans = 0;
    if(3*a > b){
        ans = (n/3) * b;
        n = n%3;
        if(n*a > b){
            ans += b;
        }
        else{
            ans += n*a;
        }
    }
    else ans  = a*n;
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
