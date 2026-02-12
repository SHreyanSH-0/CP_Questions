#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int a,b;
    cin>>a>>b;
    if(a>=b) cout<<"Alice"<<endl;
    else{
        int x = 3*a - 2*b;
        if(x<0){
            cout<<"Alice"<<endl;
            return;
        }
        a -= x;
        b -= x;
        int g = gcd(a,b);
        if(a/g==2&&b/g==3) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
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
