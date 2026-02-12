#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int rec(vector<vector<int>> &v,int bac,int i,vector<vector<int>> &dp){
    if(i>=v[0].size()) return 0;
    if(i==v[0].size()-1){
        return dp[bac][i]=v[bac][i];
    }

    if(dp[bac][i] !=-1 ) return dp[bac][i];
    
    if(i==0){
        int a = v[0][0] + rec(v,1,i+1,dp);
        int b = v[1][0] + rec(v,0,i+1,dp);
        return dp[bac][i] = max(a,b);
    }
    else{
        int a,b;
        
        if(bac==0){
            a = v[0][i] + rec(v,1,i+1,dp);
            b = v[1][i] + rec(v,0,i+1,dp);
        }
        else{
            a = v[1][i] + rec(v,1,i+1,dp);
            b = v[2][i] + rec(v,0,i+1,dp);
        }        
        return dp[bac][i]=max(a,b);
    }

}

void solve()
{
    int n;
    cin>>n;

    vector<vector<int>> v(3,vector<int>(n));
    vector<vector<int>> dp(2,vector<int>(n,-1));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<rec(v,0,0,dp)<<endl;

}
int main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
