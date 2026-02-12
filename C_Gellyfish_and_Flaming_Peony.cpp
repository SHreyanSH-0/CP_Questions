#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int rec(vector<int>&v,int i, int g, int started, int req,vector<vector<int>>&dp){
    if(i>=v.size()) return g==req?0:1e8;
    if(dp[i][g]!=-1) return dp[i][g];
    int p = INT_MAX, np = INT_MAX;
    if(!started){
        p = rec(v,i+1,v[i],1,req,dp);
        np = rec(v,i+1,0,0,req,dp);
    }
    else{
        if(g!=req)
        p = 1 + rec(v,i+1,__gcd(v[i],g),1,req,dp);
        np = rec(v, i+1,g,1,req,dp);
    }
    return dp[i][g]= min(p,np);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int ans = 0;
    int g;
    int ct = 0;
    int m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(i==0) g = v[i];
        else g = __gcd(v[i],g);
        m = max(m,v[i]);
    }  

    
    for (int i = 0; i < n; i++)
    {
        if(v[i]!=g) ct++;
    }  
    
    if(ct==n){
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        cout<<rec(v,0,0,0,g,dp) + n - 1<<endl;
    }
    else{
        cout<<ct<<endl;
    }
    
}
signed main() {
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
