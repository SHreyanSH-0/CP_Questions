#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// int rec(vector<vector<int>>& v,int i, int j,int row,vector<vector<int>> &dp){

//     cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;

//     if(row>=v.size()) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int hold = 0;

//     for (int l = 0; l < v[0].size(); l++)
//     {
//         if(l==i||l==j) continue;
//         if(row==0) hold = max(hold, v[row][l]+rec(v,l,j,row+1,dp));
//         else if(row==1) hold = max(hold, v[row][l]+rec(v,i,l,row+1,dp));
//         else hold = max(hold, v[row][l]);
//     }

//     return dp[i][j]=hold;

// }

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(3, vector<int>(n));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for (int x = 0; x < 3; x++)
    {
        int i1=-1, i2=-1, i3=-1,i4=-1,i5=-1;
        int m1 = 0, m2 = 0, m3 = 0,m4 = 0,m5 = 0;
        for (int i = 0; i < n; i++)
        {
            if (m1 < v[x][i])
            {
                m1 = v[x][i];
                i1 = i;
            }
        }

        int r2 = (x + 1) % 3;
        int r3 = (x + 2) % 3;
        
        for (int i = 0; i < n; i++)
        {
            if(i==i1) continue;
            if (m2 < v[r2][i])
            {
                m2 = v[r2][i];
                i2 = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(i==i1||i==i2) continue;
            if (m3 < v[r3][i])
            {
                m3 = v[r3][i];
                i3 = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if(i==i1) continue;
            if (m4 < v[r3][i])
            {
                m4 = v[r3][i];
                i4 = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(i==i1||i==i4) continue;
            if (m5 < v[r2][i])
            {
                m5 = v[r2][i];
                i5 = i;
            }
        }

        ans = max(ans,max(m1+m2+m3,m1+m4+m5));
        
    }

    cout<<ans<<endl;
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

    // cout<<rec(v,n,n,0,dp)<<endl;
}
int main()
{

    ll test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
