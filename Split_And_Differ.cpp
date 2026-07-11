#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

bool rec(vector<int>&v, int i, int prev,vector<vector<int>>&dp, vector<vector<int>>&par){
    if(i>=v.size()) return true;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    bool b = false, nb = false, b2 = false;
    if(prev == -1){
        if(v[i]>=3){
            b = rec(v,i+1,1,dp,par);
            b2 = rec(v,i+1,2,dp,par);
        }
        nb = rec(v,i+1,0,dp,par);
    }
    else{
        int p = v[i-1] - 1;
        if(prev == 1){
            p = v[i-1] - 1;
        }
        else if(prev == 2){
            p = 1;
        }
        else{
            p = v[i-1];
        }

        if(p<=0) return false;

        if(v[i]==p){
            if(p==1||p==2) return false;
            else{
                b = rec(v,i+1,1,dp,par);
                b2 = rec(v,i+1,2,dp,par);
            }
        }
        else{
            if(p != 1 && v[i]>=3){
                b = rec(v,i+1,1,dp,par);
            }
            else if(p != v[i] - 1&& v[i]>=3){
                b2 = rec(v,i+1,2,dp,par);
            }
            nb = rec(v,i+1,0,dp,par);
        }
    }

    if(b) {par[i][prev+1] = 1; return dp[i][prev+1] =  true;}
    else if(nb) {par[i][prev+1] = 0;return dp[i][prev+1] = true;}
    else if(b2) {par[i][prev+1] = 2;return dp[i][prev+1] =true;}
    else return dp[i][prev+1] =false;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<vector<int>> dp(n,vector<int>(4,-1));
    vector<vector<int>> par(n,vector<int>(4,-1));

    if(rec(v,0,-1,dp,par)){
        vector<int> b;
        int prev = -1;
        for (int i = 0; i < n; i++)
        {
            if(par[i][prev+1]==0){
                b.push_back(v[i]);
                prev = 0;
            }
            else if(par[i][prev+1]==1){
                b.push_back(1);
                b.push_back(v[i]-1);
                prev = 1;
            }
            else{
                b.push_back(v[i]-1);
                b.push_back(1);
                prev = 2;
            }
        }

        cout<<b.size()<<endl;
        for (int i = 0; i < b.size(); i++)
        {
            cout<<b[i]<<" ";
        }cout<<endl;
        
    }
    else cout<<-1<<endl;
    
    
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
