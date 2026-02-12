#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int dp[101][101][27][2];
int rec(vector<vector<vector<int>>> &v, int m, int lu, int prev, int turn){
    if(dp[m][lu][prev+1][turn]!=-1) return dp[m][lu][prev+1][turn];
    if(turn==0){
        int a = 1;
        for (int i = 0; i < v[m].size(); i++)
        {
            int hold = 1;
            if(v[m][i][1]>=prev){
                hold = rec(v,v[m][i][0],lu,v[m][i][1],1);
            }
            if(hold==0||a==0) a=0;
            else a = 1;
        }
        return dp[m][lu][prev+1][turn] = a;       
    }
    else{
        int a = 0;

        for (int i = 0; i < v[lu].size(); i++)
        {
            int hold = 0;
            if(v[lu][i][1]>=prev){
                hold = rec(v,m,v[lu][i][0],v[lu][i][1],0);
            }
            if(hold==1||a==1) a=1;
            else a = 0;
        }
        return dp[m][lu][prev+1][turn] = a;
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<vector<int>>> v(n+1);
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < m; i++)
    {
        int a,b;
        char c;
        cin>>a>>b>>c;
        v[a].push_back({b,c-'a'});
    }
    vector<string> ans(n,string(n,'a'));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if(dp[i][j][0][0]==-1)
            rec(v,i,j,-1,0);
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if( dp[i][j][0][0]==0) ans[i-1][j-1] = 'A';
            else ans[i-1][j-1] = 'B';
        }
        
    }
    

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    
    

}
signed main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
