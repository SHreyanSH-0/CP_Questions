#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(vector<int> &v, int i, int started, int m,vector<vector<vector<int>>> &dp){
    if(i>=v.size()) return (m>0 ? -m: m);
    int a = 0, b = 0;
    if(dp[i][m+30][started]!=-1) return dp[i][m+30][started];
    if(!started){
        a = v[i] + rec(v,i+1,1,max(m,v[i]),dp);
        b = rec(v,i+1,0,0,dp);
    }
    else{
        a = v[i] + rec(v,i+1,1,max(m,v[i]),dp);
        int hold = (max(m,v[i])>0 ? -max(m,v[i]) : max(m,v[i]));
        b = v[i] + hold;
    }
    return dp[i][m+30][started] = max(a,b);
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

    vector<vector<vector<int>>> dp(n,vector<vector<int>>(61,vector<int>(2,-1)));
    
    cout<<rec(v,0,0,0,dp)<<endl;
}
signed main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
