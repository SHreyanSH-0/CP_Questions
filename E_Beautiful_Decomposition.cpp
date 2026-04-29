#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int dp[1000000][2];
int rec(string&s, int i,int carry){
    if(i>=s.size()) return carry;
    if(dp[i][carry]!=-1) return dp[i][carry];
    int d = 1e8, nd = 1e8;
    if(carry + s[i]-'0' == 2){
        d = rec(s,i+1, 1);
    }
    else if(carry + s[i]-'0'==1){
        nd = 1+rec(s,i+1,0);
        d = 1 + rec(s,i+1,1);
    }
    else{
        nd = rec(s,i+1,0);
    }

    return dp[i][carry]=min(d,nd);
}

void solve()
{
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    memset(dp,-1,sizeof(dp));
    cout<<rec(s,0,0)<<endl;
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
