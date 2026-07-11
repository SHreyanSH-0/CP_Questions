#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int r,y;
    cin>>r>>y;

    int ans ;
    if(r>y){
        ans = r;
    }
    else if(r>0){
        ans = r + (y -  r)/2;
    }
    else{
        ans = y/2;
    }

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
