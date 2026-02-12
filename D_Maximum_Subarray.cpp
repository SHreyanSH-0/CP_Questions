#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define int long long

int rec(vector<int>&v, int i, int k, int x,int x2,bool start,vector<vector<vector<int>>> &dp){
    if(i>=v.size()) return k==0?0:-1e8;
    if(dp[i][k][start]!=-1) return dp[i][k][start];
    if(!start){
        int np = 0;
        int a = 0, b = 0;

        if(x2>0){
            a = rec(v,i+1,k,x,x2-1,false,dp);
        }
        if(k>0){
            b = rec(v,i+1,k-1,x,x2,false,dp);
        }

        np = max(np,max(a,b));
       
        int p = 0;
        if(1){
            int plus = 0, minus = 0;
            if(x2>0&&v[i]-x>0){
                minus = v[i]-x+ rec(v,i+1,k,x,x2-1,true,dp);
                p = max(p,v[i]-x);
            }
            if(k>0&&v[i]+x>0){
                p = max(p,v[i]+x);
                plus = v[i] + x + rec(v,i+1,k-1,x,x2,true,dp);
                
            }
            p = max(p,max(plus,minus));
        }   
        return dp[i][k][start]= max(p,np);
    }
    else{
        int p = 0;
        if(1){
            int plus = 0, minus = 0;
            if(x2>0){
                minus = v[i]-x+ rec(v,i+1,k,x,x2-1,true,dp);
                p = max(p,v[i]-x);
            }
            if(k>0){
                p = max(p,v[i]+x);
                plus = v[i] + x + rec(v,i+1,k-1,x,x2,true,dp);
                
            }
            p = max(p,max(plus,minus));
        }   
        return dp[i][k][start]= p;
    }

}

void solve()
{
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
    cout<<rec(v,0,k,x,n-k,false,dp)<<endl;
       
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
