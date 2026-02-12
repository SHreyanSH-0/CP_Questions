#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<vector<short>>> dp(n+1,vector<vector<short>>(k+1,vector<short>(k+1,0)));
    set<int> s;
    dp[0][0][0] = 1;
    
    for(int i=1;i<=n;i++){
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; l <= k; l++)
            {
                dp[i][j][l] = dp[i-1][j][l];
                if(j-v[i-1]>=0&&l-v[i-1]>=0) dp[i][j][l] = dp[i][j][l]||dp[i-1][j-v[i-1]][l-v[i-1]];
                if(j-v[i-1]>=0) dp[i][j][l] = dp[i][j][l]||dp[i-1][j-v[i-1]][l];
                if(dp[i][k][l]) s.insert(l);
            }
        }
    }
    
    cout<<s.size()<<endl;
    for (auto &it:s)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
int main() {

    int test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
