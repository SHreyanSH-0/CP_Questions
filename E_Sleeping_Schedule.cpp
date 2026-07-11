#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int dp[2000][2000];

int rec(vector<int> & v , int i, int hour, int h, int l, int r) {
    if(i>=v.size()) return 0;
    if(dp[i][hour]!=-1) return dp[i][hour];
    int ans = 0;

    if((hour + v[i] - 1)%h >= l &&(hour + v[i] - 1)%h <= r ) ans = 1 + rec(v,i+1,(hour + v[i] - 1)%h,h,l,r);
    else ans = rec(v,i+1,(hour + v[i] - 1)%h,h,l,r);
    if((hour + v[i])%h >= l &&(hour + v[i])%h <= r ) ans = max(ans,1 + rec(v,i+1,(hour + v[i])%h,h,l,r));
    else ans = max(ans, rec(v,i+1,(hour + v[i])%h,h,l,r));

    return dp[i][hour]=ans;
}

void solve()
{
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(v,0,0,h,l,r);
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
