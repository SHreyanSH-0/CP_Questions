#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int MOD = 1e9 +7;
 
int rec(vector<int>&v,int i, int num, vector<vector<int>>&dp,int k){
    if(i>=v.size()) return __builtin_popcount(num) == k;
    int hold = num==127?-1:num;
    if(dp[i][hold+1]!=-1) return dp[i][hold+1];
 
    int p = rec(v,i+1,num&v[i],dp,k)%MOD;
    int np = rec(v,i+1,num,dp,k)%MOD;
    
 
    return dp[i][hold+1] = (p + np)%MOD;
}
 
void solve() {
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    vector<vector<int>> dp(n,vector<int>(65,-1));
    cout<<rec(a,0,127,dp,k)<<endl;
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
