#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    if((3*n-m)%2==1) cout<<"NO"<<endl;
    else{
        int x = (3*n-m)/2;
        if(x<=n && x >= 0 && x + 3*(n-x)==m) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    } 
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
