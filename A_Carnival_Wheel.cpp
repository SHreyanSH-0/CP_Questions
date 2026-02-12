#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int start = (a + b)%n;
    int ans = a;
    while(start!=a){
        ans = max(ans,start);
        start = (start + b)%n;
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
