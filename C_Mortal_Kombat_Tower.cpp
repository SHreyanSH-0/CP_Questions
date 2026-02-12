#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(vector<int>&v, int i, int chance,vector<vector<int>>&dp){
    if(i>=v.size()) return 0;
    if(dp[i][chance]!=-1) return dp[i][chance];
    int killOne = INT_MAX, killTwo = INT_MAX;

    if(chance == 0){
        
        killOne = v[i] + rec(v,i+1,1,dp);
        if(i+1<v.size()){
            killTwo = v[i] + v[i+1] + rec(v,i+2,1,dp);
        }
    }
    else{
        killOne = rec(v,i+1,0,dp);
        if(i+1<v.size()){
            killTwo = rec(v,i+2,0,dp);
        }
    }
    return dp[i][chance]=min(killOne,killTwo);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    vector<vector<int>> dp(n,vector<int>(2,-1));
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    cout<<rec(v,0,0,dp)<<endl;    
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
