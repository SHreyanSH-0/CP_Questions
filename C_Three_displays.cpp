#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int dp[3001][3001][3];
int rec(vector<int>&s,vector<int>&c,int i, int prev, int ct){
    if(ct==3) return 0;
    if(i>=s.size()) return ct==3?0:1e9;
    if(dp[i][prev+1][ct]!=-1) return dp[i][prev+1][ct];
    int p = 1e9, np = 1e9;

    if(prev==-1){
        p = c[i] + rec(s,c,i+1,i,ct+1);
        np = rec(s,c,i+1,prev,ct);
    }
    else{

        if(s[i]>s[prev])
        p = c[i] + rec(s,c,i+1,i,ct+1);
        np = rec(s,c,i+1,prev,ct);
    }
    return dp[i][prev+1][ct] = min(p,np);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> s(n),c(n);
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }
    memset(dp,-1,sizeof(dp));
    int hold = rec(s,c,0,-1,0);
    int ans = hold>=1e9? -1: hold;
    cout<<ans;
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
