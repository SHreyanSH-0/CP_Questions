#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int rec(string &a, string &b, int i, int j, int moda,vector<vector<int>>& dp){
    if(i>=a.size() && j>=b.size()) return moda == 0? 0 : -1e8;
    // if(i>=a.size() || j>=b.size()) return -1e8;
    if(dp[i][j]!=-1) return dp[i][j];
    int m = 0, nm = -1e9;
    if(i<a.size() && j <b.size() && (a[i] - '0' - (b[j] - '0') + moda)%10 == 0 ) {
        nm = 1 + rec(a,b,i+1,j+1,0,dp);
    }

    int sign1 = 1;
    int sign2 = 1;
    int hold1 = i<a.size() ? moda + a[i] - '0':0;
    int hold2 = j<b.size() ?moda - (b[j] - '0'):0;

    if(hold1<0) sign1 = -1;
    if(hold2<0) sign2 = -1;

    hold1 = abs(hold1)%10;
    hold2 = abs(hold2)%10;

    int h1 = i<a.size() ? rec(a,b,i+1,j,sign1*hold1,dp) : -1e8;
    int h2 = j<b.size() ? rec(a,b,i,j+1,sign2*hold2,dp) : -1e8;

    int p = max(h1,h2);

    return dp[i][j]=max(p,nm);
}

void solve()
{
    string a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
    int ans = rec(a,b,0,0,0,dp);
    if(ans<=0) cout<<-1<<endl;
    else cout<<ans<<endl;
}
int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
