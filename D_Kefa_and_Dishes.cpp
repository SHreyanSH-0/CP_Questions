#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(vector<int> &v,vector<vector<int>> &v2,int m, int prev,vector<vector<int>>&dp,int e){
    if(m==0) return 0;
    if(dp[e][prev]!=-1) return dp[e][prev];
    int eat = 0;
    int ans = 0;
    for(int ind = 1;ind<v.size();ind++){
        if (e & (1 << (ind - 1))) continue;

        int hold = v[ind];
        eat = hold + rec(v,v2,m-1,ind,dp,(e|(1<<(ind-1))));
        ans = max(ans,eat + v2[prev][ind]);
    }

    return dp[e][prev] =ans;
    
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(n+1);
    vector<vector<int>> v2(n+2,vector<int>(n+2,0));
    vector<vector<int>> dp((1<<(n+1)), vector<int>(n+1,-1));
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }

    for (int i = 0; i < k; i++)
    {
        int x ,y ,c;
        cin>>x>>y>>c;
        v2[x][y] = c;
    }

    
    cout<< rec(v,v2,m,0,dp,0);
    return;
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
