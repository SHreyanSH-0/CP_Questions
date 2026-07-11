#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 998244353

long long p(long long a,long long b){
    long long ans = 1;
    while(b>0){
        if(b%2==1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b/=2;
    }
    return ans;
}

int inv(int a){
    return p(a,mod-2);
}


void solve()
{
    int n,k;
    cin>>n>>k;

    vector<long long> fact(n+1), infact(n+1);
    fact[0] = infact[0] = 1;
    for(int i=1;i<=n;i++){
        fact[i] = (fact[i-1] * i)%mod;
        infact[i] = inv(fact[i]);
    }
    
    int ans = 0;
    
    for (int i = 1; i <=k; i++)
    {
        int next = (((fact[n-i]*infact[n-k])%mod)*infact[k - i])%mod; // (n-i)C(n-k)
        int curr = (p(i,k) - p(i-1,k) + mod)%mod;
        ans += (next * curr)%mod;
        ans %= mod;
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
