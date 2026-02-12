#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

double rec(double w, double b,vector<vector<double>> &dp){
    if(w<=0||b<0) return 0;

    if(b==0){
        return 1;
    }
    if(dp[w][b]!=-1) return dp[w][b];

    double one = w/(w+b);
    
    double two = 0;
    if(b>=2)
    two = ( b/(b+w) )*((b-1)/(b+w-1))*(rec(w-1,b-2,dp)*(w/(w+b-2)));
    
    double three = 0;
    if(b>=2)
    three = (b/(b+w))*((b-1)/(b+w-1))*(rec(w,b-3,dp)*((b-2)/(w+b-2)));

    return dp[w][b] = one + two + three;
}

void solve()
{
    double w , b ;
    cin>>w>>b;

    vector<vector<double>> dp(w+1,vector<double>(b+1,-1));
    cout<<fixed<<setprecision(9)<<rec(w,b,dp);
}
int main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
