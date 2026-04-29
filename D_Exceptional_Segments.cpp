#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 998244353
void solve()
{
    int n,x;
    cin>>n>>x;
    int a = 0;
    // for(int i=1;i<=n;i++){
    //     a = a^i;
    //     cout<<a<<" ";

    // }cout<<endl;
    if(1){
        int lo = (x-1)/4 + 1;
        int ro = (n-1)/4 + 1 - lo;

        int lz = x>=3?(x-3)/4 + 1:0;
        int rz =  (n>=3?(n-3)/4 + 1:0) - lz;

        if((x-1)%4==0) {
            lo--;
            ro++;
        }
        else if((x-1)%4==2){
            lz--;
            rz++;
        }
        // lz = max(lz,0LL);
        // rz = max(rz,0LL);
        // lo = max(lo,0LL);
        // ro = max(ro,0LL);

        int ans = (((lo%mod)*(ro%mod))%mod + (((lz+1)%mod)*(rz%mod))%mod);
        cout<<ans%mod<<endl;
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
