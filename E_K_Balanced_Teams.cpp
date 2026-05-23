#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(vector<int>&v,int i,int k,vector<vector<int>> &dp){
    if(i>=v.size() || k<=0) return 0;
    if(dp[i][k]!=-1) return dp[i][k];
    int idx = upper_bound(v.begin(),v.end(),v[i] + 5) - v.begin();
    
    int a = 0, b = 0;
    
    if(idx-1<v.size()){
        a = idx - i + rec(v,idx,k-1,dp);
    } 

    b = rec(v,i+1,k,dp);

    return dp[i][k] = max(a,b);
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    
    sort(v.begin(),v.end());

    cout<<rec(v,0,k,dp);
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
