#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000000

int rec(int n1,int n2,int k1,int k2, int i, int j,vector<vector<vector<vector<int>>>>& dp){
    if(n1==0&&n2==0) return 1;
    if(n1<0||n2<0) return 0;
    if(dp[n1][n2][i][j] != -1) return dp[n1][n2][i][j];

    if(i>0&&j>0){
        return dp[n1][n2][i][j] = (rec(n1,n2-1,k1,k2,k1,j-1,dp)%mod + rec(n1-1,n2,k1,k2,i-1,k2,dp)%mod )%mod ;
    }
    else if(i>0&&n1>0){
        return dp[n1][n2][i][j] =  rec(n1-1,n2,k1,k2,i-1,k2,dp)%mod ;
    }
    else if(j>0&&n2>0) {
        return dp[n1][n2][i][j] = rec(n1,n2-1,k1,k2,k1,j-1,dp)%mod ;
    }
    return 0;
}


void solve()
{
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    vector<vector<vector<vector<int>>>> dp(n1+1, vector<vector<vector<int>>> (n2+1,vector<vector<int>> ( k1+1,vector<int>(k2+1,-1))));
    
    cout<<rec(n1,n2,k1,k2,k1,k2,dp)%mod<<endl;
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
