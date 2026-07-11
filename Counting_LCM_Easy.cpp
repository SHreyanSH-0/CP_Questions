#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

bool isprime(int n){
    int l = sqrt(n);
    for(int i=2;i<=l;i++) if(n%i==0) return false;
    return true;
}

int f(int l,int r){
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        if(isprime(i)) ans++;
    }
    return ans;
    
}

void solve()
{
    int z;
    cin>>z;
    int ans = 0;

    for (int i = 1; i < z; i++)
    {
        int x = z/i;
        int y  = z/i;
        // a*b > z*i
        
        int r = x*y;
        int l = z*i + 1;
        cout<<i<<" "<<r<<" "<<l<<endl;
        if(r>=l) {
            ans = ans + (r-l+1) - (r-l+1)/i - f(l,r);
        }
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
