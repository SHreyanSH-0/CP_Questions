#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int ans = 0;

int fun(int a, int b){
    int an = 1;
    while(b>0){
        if(b%2==1){
            an *= a;
        }
        a = a*a;
        b/=2;
        an%=mod;
        a%=mod;
    }
    return an;
}

int rec(vector<vector<int>> &v, int node, int par, int n){
    int ct = 1;
    int n2 = n - 1;
    for(auto &it:v[node]){
        if(it==par) continue;
        int hold = rec(v,it,node,n);
        ct += hold;
        n2-=hold;
        ans += hold*n2;
        ans %=mod;
    }

    return ct;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> v(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(k==1||k==3) cout<<1<<endl;
    else{
        ans = (n*(n-1))%mod;
        rec(v,1,-1,n);
        int hold = (n*(n-1))/2;
        hold%=mod;
        int h = fun(hold,mod-2);
        ans = (ans*h)%mod;
        cout<<ans<<endl;
    }
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
