#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(string &a, string &b, int i, int even,vector<vector<int>> &dp){
    if(i>=a.size()) return 0;
    if(dp[i][even]!=-1) return dp[i][even];
    int newEven = (even + a[i] - '0')%2;
    int ans = 0;
    if(newEven&&b[i]=='1'){
        ans = min(1 + rec(a,b,i+1,0,dp), 1 + rec(a,b,i+1,1,dp));
    }
    else if(!newEven&&b[i]=='0'){
        ans = min(1 + rec(a,b,i+1,0,dp), 1 + rec(a,b,i+1,1,dp));
    }
    else {
        ans = rec(a,b,i+1,newEven,dp);
    }
    return dp[i][even]=ans;
}

void solve()
{
    string a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a.size(),vector<int>(2,-1));
    cout<<rec(a,b,0,1,dp)<<endl;
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
