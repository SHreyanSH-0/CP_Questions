#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

bool rec(string &s,string&t,int i, int l,int r,vector<vector<vector<int>>>&dp){
    if(i>=s.size()) return true;
    if(dp[i][t[l]-'a'][t[r]-'a']!=-1) return dp[i][t[l]-'a'][t[r]-'a'];
    int a = 0,b = 0;
    if(s[i]=='?'){
        a = rec(s,t,i+1,l+1,r,dp);
        b = rec(s,t,i+1,l,r-1,dp);
    }
    else{
        if(s[i]==t[l]&&s[i]==t[r]){
            a = rec(s,t,i+1,l+1,r,dp);
            b = rec(s,t,i+1,l,r-1,dp);
        }
        else if(s[i]==t[l]){
            a = rec(s,t,i+1,l+1,r,dp);
        }
        else if(s[i]==t[r]){
            a = rec(s,t,i+1,l,r-1,dp);
        }
        else{
            return dp[i][t[l]-'a'][t[r]-'a'] = false;
        }
    }
    return dp[i][t[l]-'a'][t[r]-'a'] = a|b;
}

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t;
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
    for (int i = 0; i < n; i++)
    {
        if(i%2==0) t.push_back('a');
        else t.push_back('b');
    }   
    int i = 0, j = n-1;
    if(rec(s,t,0,0,n-1,dp)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
     
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
