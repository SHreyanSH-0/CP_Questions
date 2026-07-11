#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int dp[200][200][201];
int rec(string&a,string&b, int i, int preva, int k){
    if(i>=a.size()) return 0;
    if(dp[i][preva][k]!=-1) return dp[i][preva][k];
    int p = 0, np = 0;
    if(a[i] == b[0]){
        if(b[0] == b[1]){
            np = preva + rec(a,b,i+1,preva + 1, k);
        }
        else{
            if(k > 0) p = preva + rec(a,b,i+1,preva,k-1);
            np = rec(a,b,i+1,preva + 1, k);
        }
    }
    else if(a[i] == b[1]){
        if(k > 0) p = rec(a,b,i+1,preva + 1, k-1);
        np = preva + rec(a,b,i+1,preva,k);
    }
    else{
        if(b[0] == b[1]){
            if(k > 0) p = preva + rec(a,b,i+1,preva+1,k-1);
            np = rec(a,b,i+1,preva, k);
        }
        else{
            if(k > 0) p = max(preva + rec(a,b,i+1,preva,k-1), rec(a,b,i+1,preva + 1, k-1));
            np = rec(a,b,i+1,preva, k);
        }
    }
    return dp[i][preva][k] = max(p,np);
}

void solve()
{
    int n,k;
    cin>>n>>k;
    string a,b;
    cin>>a>>b;

    memset(dp,-1,sizeof(dp));
    cout<<rec(a,b,0,0,k);

    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
