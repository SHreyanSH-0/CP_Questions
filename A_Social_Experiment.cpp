#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    if(n==2 ) cout<<2<<endl;
    else if(n==3 ) cout<<3<<endl;
    else if(n%4==0) cout<<0<<endl;
    else{
        int a = n/4;
        int b = n%4;
        if(b==0||b==2) cout<<0<<endl;
        else if(b==1||b==3) cout<<1<<endl;
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
