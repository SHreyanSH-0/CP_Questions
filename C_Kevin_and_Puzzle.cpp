#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 998244353

int rec(vector<int>&v, int i, int prev, vector<vector<int>>&dp){
    if(i>=v.size()) return 1;
    if(dp[i][prev]!=-1) return dp[i][prev];
    int l = 0;
    int nl = 0;
    if(prev==0){
        l = rec(v,i+1,1,dp);
        if(i==0){
            if(v[i]==0) nl = rec(v,i+1,0,dp);
        }
        else if(v[i]==v[i-1]) nl = rec(v,i+1,0,dp);
    } 
    else{
        if(i==1){
            if(v[i]==1) nl = rec(v,i+1,0,dp);
        }
        else{
            if(v[i]== 1 + v[i-2]) nl = rec(v,i+1,0,dp);
        }
    }
    return dp[i][prev] = (l + nl)%mod;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<vector<int>>dp(n,vector<int>(2,-1));
    cout<<rec(v,0,0,dp)<<endl;
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
