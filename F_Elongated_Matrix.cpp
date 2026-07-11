#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int dp[1<<16][17][16];
int rec(vector<vector<int>> &v, int bits, int prev, int first,vector<vector<int>> &hold,vector<vector<int>> &hold2){
    if(bits == (1<<v.size()) - 1){
        return hold2[prev][first];
    }

    if(dp[bits][prev+1][first]!=-1) return dp[bits][prev+1][first];

    int ans = 0;
    for(int row = 0;row<v.size();row++){
        if(((1<<row)&(bits)) == 0){
            if(prev==-1){
                ans = max(ans, rec(v,bits|(1<<row),row,row,hold,hold2));
            }
            else{
                int mini = hold[row][prev];
                ans = max(ans, min(mini,rec(v,bits|(1<<row),row,first,hold,hold2)));
            }
        }   
    }
    return dp[bits][prev+1][first]=ans;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>v[i][j];
        }
    }

    vector<vector<int>> hold(16,vector<int>(16)), hold2(16,vector<int>(16));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int mini = 1e9;
            for(int col = 0;col<v[0].size();col++){
                mini = min(abs(v[i][col] - v[j][col]), mini);
            }

            hold[i][j] = mini;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int mini = 1e9;
            for(int col = 1;col<v[0].size();col++){
                mini = min(abs(v[i][col-1] - v[j][col]), mini);
            }

            hold2[i][j] = mini;
        }
        
    }
    

    cout<<rec(v,0,-1,0,hold,hold2);

    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
