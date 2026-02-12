#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int rec(int n, int a, int b, int c,vector<int> &dp){
    if(n==0) return 0;
    if(n<0) return -1e8;

    if(dp[n]!=-1) return dp[n];

    int n1 = 1 + rec(n-a,a,b,c,dp);
    int n2 = 1 + rec(n-b,a,b,c,dp);
    int n3 = 1 + rec(n-c,a,b,c,dp);

    return dp[n] = max(n1,max(n2,n3));
}

void solve()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;

    vector<int> dp(n+1,-1);

    cout<< rec(n,a,b,c,dp);
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
