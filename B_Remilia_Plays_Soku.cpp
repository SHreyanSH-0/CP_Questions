#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,x1,x2,k;
    cin>>n>>x1>>x2>>k;

    if(n<=3) cout<<1<<endl;
    else{
        int d1 = abs(x1 - x2);
        int d2 = n - d1;
        d1--;
        d2--;

        cout<<min(d1,d2) + k + 1<<endl;
        
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
