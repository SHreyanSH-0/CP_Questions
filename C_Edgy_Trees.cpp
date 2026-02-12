#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

class dsu{
    public:
    vector<int> par, size;

    dsu(int n){
        for (int i = 0; i <= n; i++)
        {
            par.push_back(i);
            size.push_back(1);
        }
    }

    int parent(int n){
        if(par[n]!=n) par[n] = parent(par[n]);
        return par[n];
    }

    void comb(int a,int b){
        int para = parent(a);
        int parb = parent(b);
        if(para==parb) return;

        if(size[parb]>size[para]){
            par[para] = parb;
            size[parb] += size[para];
        }
        else{
            par[parb] = para;
            size[para]+=size[parb];
        }
    }

    int f(int n) {return size[n];}
};

int fun(int n, int k){
    if(n==0) return 0;
    int a = 1;
    for(int i=0;i<k;i++) a = a*n%mod;
    return a;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<vector<vector<int>>> v(n+1);
    dsu d(n);
    for (int i = 0; i < n-1; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        if(c==0) d.comb(a,b);
    }
    int ans = 0;
    int hold = 0;
    int ct = 0;
    for (int i = 1; i <= n; i++)
    {
        if(d.f(i)>1&&d.parent(i)==i){
            ct+=d.f(i);
            hold += fun(d.f(i),k);
            hold = hold%mod;
        }
    }
    
    ans = ((fun(n,k)%mod -hold%mod  + mod)%mod - n + ct)%mod;    
    cout<<ans<<endl;
}
signed main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
