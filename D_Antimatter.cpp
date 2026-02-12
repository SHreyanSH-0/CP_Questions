#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
#define mod 1000000007
int dp[1000][20002][2];
int rec(vector<int> &v, int i,int sum, int started){
    if(i>=v.size()) return sum==0&&started;
    if(dp[i][sum+10000][started]!=-1) return dp[i][sum+10000][started];
    int ans;
    if(!started){
        ll m = rec(v,i+1,sum+v[i],1);
        int a = rec(v,i+1,sum-v[i],1);
        int n = rec(v,i+1,sum,0);
        ans = ((m+a)%mod+n)%mod;
    }
    else{
        ll m = rec(v,i+1,sum+v[i],1);
        int a = rec(v,i+1,sum-v[i],1);
        int n = sum==0;
        ans = ((m+a)%mod+n)%mod;
    }
    return dp[i][sum+10000][started] = ans%mod;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<rec(v,0,0,0)<<endl;
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
