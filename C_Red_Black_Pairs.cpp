#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(string &s, string &t, int i,vector<int>&dp){
    if(i>=s.size()) return 0;
    int h = 1e8, v = 1e8;
    if(dp[i]!=-1) return dp[i];
    if(i+1<s.size()){
        if(s[i]==s[i+1]){
            if(t[i]==t[i+1]) h = rec(s,t,i+2,dp);
            else h = 1 + rec(s,t,i+2,dp);
        }
        else {
            if(t[i]==t[i+1]) h = 1 + rec(s,t,i+2,dp);
            else h = 2 + rec(s,t,i+2,dp);
        }
    }
    
    if(s[i]==t[i]) v = rec(s,t,i+1,dp);
    else v = 1 + rec(s,t,i+1,dp);

    return dp[i] = min(h,v);
}

void solve()
{
    int n;
    cin>>n;
    string t,b;
    cin>>t;
    cin>>b;

vector<int>dp(n,-1);
cout<<rec(t,b,0,dp)<<endl;

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
