#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 998244353
void solve()
{
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<m+1<<endl;
        return;
    }
    int a = 0;
    int pow = 1;
    int hold = m;
    while(hold>0){
        if(hold%2==0) a+=pow;
        hold/=2;
        pow*=2;
    }
    cout<<(m - (a - 1))%mod<<endl;
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
