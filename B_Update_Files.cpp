#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n,k;
    cin>>n>>k;
    if(n==1){
        cout<<0<<endl;
    }
    else if(k==1){
        cout<<n-1<<endl;;
    }
    else{
        ll hold = 1;
        ll kHold = k;
        int p = 0;
        while (kHold>0&&hold<n)
        {
            hold*=2;
            kHold/=2;
            p++;
        }
        
        
        n = n-hold;
        ll ans = p;
        if(n>0) ans += ceil((double)(n)/k);
        
        cout<<ans<<endl;
    }
}
int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
