#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 998244353

int dp[4096][4096];

bool isPrime(int n){
    if(n==1) return false;
    int l = sqrt(n);
    for(int i=2;i<=l;i++){
        if(n%i==0) return false;
    }
    return true;
}

int fact(int n){
    long long fact = 1;
    for(int i=1;i<=n;i++) fact = (fact*i)%mod;
    return fact;
}

int po(int n, int p){
    long long ans = 1;
    while(p>0){
        if(p%2==1) ans *= n;
        n = (n*n)%mod;
        ans%=mod;
        p/=2;
    }
    return (ans);
}

long long rec(vector<pair<int,int>>&v, vector<pair<int,int>> &factor, int i, int ct , int hold,int n ){
    if(i>=v.size()){
        return ct==n/2?hold:0;
    }
    if(dp[i][ct]!=-1) return dp[i][ct];
    long long a=0;
    int h = factor[i].first;
    int h2 = factor[i].second;
    if(ct<n/2)
    a = (h*rec(v,factor,i+1,ct+1,hold,n))%mod;
    long long b = (h2*rec(v,factor,i+1,ct,hold,n))%mod;
    return dp[i][ct] = (a + b)%mod;
}

void solve()
{
    int n;
    cin>>n;
    n *=2;
    vector<int> v1(n);
    int p = 0, np = 0;
    map<int,int> nonPrime, prime;
    for (int i = 0; i < n; i++)
    {
        cin>>v1[i];
        if(isPrime(v1[i])){
            p++;
            prime[v1[i]]++;
        } 
        else{
            np++;
            nonPrime[v1[i]]++;
        } 
    }
    memset(dp,-1,sizeof(dp));

    vector<pair<int,int>> v,factor;

    for(auto&[x,y]:prime){
        v.push_back({x,y});
        int h = fact(y - 1);
        h = po(h,mod-2);
        int h2 = fact(y);
        h2 = po(h2,mod-2);
        factor.push_back({h,h2});
    }

    long long hold = fact(n/2);

    long long den = 1;

    for(auto&[x,y]:nonPrime){
        den = (den * fact(y))%mod;
    }

    den = po(den, mod - 2);

    hold = (hold * den)%mod;

    cout<<rec(v,factor,0,0,hold,n)<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
