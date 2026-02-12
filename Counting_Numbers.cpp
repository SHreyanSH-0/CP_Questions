#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
int dp[20][2][11];

int rec(string &s, int i, int prev, int tight){

    if(i==s.size()) {
        return 1;
    }

    if(dp[i][tight][prev]!=-1) return dp[i][tight][prev];

    int limit = (tight == 1) ? s[i] - '0': 9;
    
    int ans = 0;

    for(int ind=0;ind<=limit;ind++){
        if(ind == prev) continue;
        ans += rec(s, i+1, (prev==10&&ind==0)? prev: ind, tight&&(ind==limit));
    }

    return dp[i][tight][prev] = ans;
}

void solve()
{
    int l,r;
    cin>>l>>r;
    string higher = to_string(r);
    string lower = to_string(l-1);

    memset(dp,-1,sizeof(dp));
    int a = rec(higher,0,10,1);
    memset(dp,-1,sizeof(dp));
    int b = rec(lower,0,10,1);
    cout<<a-b ;
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
