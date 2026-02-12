#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 998244353

int rec(int m,int col, int comp, int a, vector<vector<vector<int>>> &dp,int prev){
    if(col>=m){        
        return comp == a;
    } 
    if(dp[col][comp][prev+1]!=-1) return dp[col][comp][prev+1]%mod;

    int ans = 0;

    for(int i=0;i<4;i++){
        if(prev==-1){
            int ct = 2;
            if(i==0||i==3) ct = 1;
            ans += rec(m,col+1,comp+ct,a,dp,i)%mod;
        }
        else{
            int ct = 1;
            if((prev==0&&i==3)||(prev==3&&i==0)) ct = 1;
            else if(prev==i||((prev==1||prev==2)&&i==3)||((prev==1||prev==2)&&i==0)) ct = 0;
            else if((prev==1&&i==2)||(i==1&&prev==2)) ct = 2;
            ans += rec(m,col+1,comp+ct,a,dp,i)%mod;
        }
    }

    return dp[col][comp][prev+1] = ans%mod;

}

void solve()
{
    int m, n;
    cin>>m>>n;

    vector<vector<vector<int>>> dp(m,vector<vector<int>>(2*m+1,vector<int>(5,-1)));

    cout<<rec(m,0,0,n,dp,-1);
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
