#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007

int dp[201][201][201];

int rec(vector<int>& red,vector<int>& green,vector<int>& blue, int i , int j , int k){
    int ans = 0;
    int a = 0,b=0,c=0;
    if(i<red.size()&&j<green.size()){
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        a = red[i]*green[j]+rec(red,green,blue,i+1,j+1,k);
    }
    if(i<red.size()&&k<blue.size()){
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        b = red[i]*blue[k] + rec(red,green,blue,i+1,j,k+1);
    }   
    if(j<green.size()&&k<blue.size()){
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        c = green[j]*blue[k] + rec(red,green,blue,i,j+1,k+1);
    }

    ans = max(a,max(b,c));
    return dp[i][j][k]=ans;
}

void solve()
{
    int r,g,b;

    cin>>r>>g>>b;

    vector<int> red(r), green(g), blue(b);

    for (int i = 0; i < r; i++)
    {
        cin>>red[i];
    }
    for (int i = 0; i < g; i++)
    {
        cin>>green[i];
    }
    for (int i = 0; i < b; i++)
    {
        cin>>blue[i];
    }

    sort(red.rbegin(),red.rend());
    sort(green.rbegin(),green.rend());
    sort(blue.rbegin(),blue.rend());

    memset(dp,-1,sizeof(dp));

    cout<<rec(red,green,blue,0,0,0);
        
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
