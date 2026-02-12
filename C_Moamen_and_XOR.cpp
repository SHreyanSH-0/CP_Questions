#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int power(int n, int p){
    int ans = 1;
    int a = n;
    while(p>0){
        if(p%2==1){
            ans*= a;
        }
        a = a*a;
        a%=mod;
        ans%=mod;
        p/=2;
    }
    return ans;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    int prev, curr;
    int hold = power(2,n-1);
    prev = 1;
    int h;
    if(n%2==0) h = hold-1;
    else h = hold;
    for(int i=1;i<=k;i++){
        curr = ((prev*h)%mod + (n%2==0? (((power(2,n*(i-1))))%mod)%mod:prev))%mod;
        prev = curr;
    }

    cout<<(prev%mod)<<endl;
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
