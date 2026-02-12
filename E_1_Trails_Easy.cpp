#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll rec(vector<int>&,vector<int>&, int, bool, int , int, vector<vector<long long>>&);

long long cabin(vector<int>& s,vector<int>&l, bool shpt,int n, int day,vector<vector<ll>>&dp){
    ll ans = 0;
    if(shpt){
        for(int i=0;i<l.size();i++){
            ans += ((s[i]+l[i])*rec(s,l,i,false,n,day+1,dp)%mod)%mod;
        }
    }
    else{
        for(int i=0;i<l.size();i++){
            if(s[i]){
                ans += (s[i] * rec(s,l,i,false,n,day+1,dp)%mod)%mod;
            }
        }
    }
    return ans;
}

long long rec(vector<int>& s,vector<int>&l, int i, bool shpt, int n , int day,vector<vector<long long>>&dp){
    if(day>=n) return 1;

    if(dp[i][day]!=-1) return dp[i][day];

    if(l[i]&&s[i]){
        return dp[i][day] = (l[i]*cabin(s,l,false,n,day,dp) + s[i]*cabin(s,l,true,n,day,dp))%mod;
    }
    else if(l[i]){
        return dp[i][day] = (l[i]*cabin(s,l,false,n,day,dp))%mod;
    }
    else if(s[i]){
        return dp[i][day] = (s[i]*cabin(s,l,true,n,day,dp))%mod;
    }
    else return dp[i][day] = 0;
}

void solve()
{
    int m,n;
    cin>>m>>n;

    vector<int> s(m), l(m);

    vector<vector<ll>>  dp(m,vector<ll>(n,-1));

    for(int i=0;i<m;i++){
        cin>>s[i];
    }
    for(int i=0;i<m;i++){
        cin>>l[i];
    }
    cout<<rec(s,l,0,false,n,0,dp);

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