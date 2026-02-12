#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
#define mod 1000000007
// int rec(int n, int i, int vertex, vector<vector<int>>&dp){
//     if(i>=n) return vertex==0;
    
//     if(dp[i][vertex]!=-1) return dp[i][vertex];
//     long long ans = 0;

//     for (int ver = 0; ver < 4; ver++)
//     {
//         if(ver==vertex) continue;
//         ans = (ans+rec(n,i+1,ver,dp))%mod;
//     }

//     return dp[i][vertex] = ans%mod;
// }

void solve()
{
    int n;
    cin>>n;
    // vector<vector<int>> dp(n,vector<int>(4,-1));
    vector<int> curr(4,0), prev(4,0);

    prev[0] = 1;
    prev[1] = 0;
    prev[2] = 0;
    prev[3] = 0;

    int ans = 0;

    for(int i=1;i<=n;i++){
        for(int v = 0;v<4;v++){
            for(int u = 0;u<4;u++){
                if(v==u) continue;
                curr[v] = (curr[v] + prev[u])%mod;
            }
        }

        for (int j = 0; j < 4; j++)
        {
            prev[j] = curr[j];
            curr[j] = 0;
        }
        
    }
    cout<<prev[0];
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
