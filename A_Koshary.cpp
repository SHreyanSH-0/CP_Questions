#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int x,y;
    cin>>x>>y;

    if(x%2==1&&y%2==1) cout<<"NO"<<endl;
    else cout<<"YES\n";
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
