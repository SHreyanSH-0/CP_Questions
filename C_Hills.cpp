#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
long long dp[2][2501][5000];
long long rec(vector<int>&v, int i, bool check, int k){
    if(i>=v.size()) return k==0?0:1e15;
    if(k==0) return dp[check][k][i] = 0;
    if(dp[check][k][i]!=-1) return dp[check][k][i];
    long long b = 1e8, nb = 1e8;
    if(i==0){
        if(v[i+1]>=v[i]) b = v[i+1] - v[i] + 1 + rec(v,i+2,false,k-1);
        if(v[i]>v[i+1]) b = min(b, rec(v,i+2,true,k-1));
        nb = rec(v,i+1,true,k);
    }
    else{
        int prev = check? v[i-1]: v[i-2] - 1;
        int hold = 0;
        if(prev<v[i]){
            if(i+1<v.size()){
                if(v[i+1]<v[i]) b = rec(v,i+2,true,k-1);
                else b = v[i+1] - v[i] + 1 + rec(v,i+2,false,k-1);
            }
            else{
                b = rec(v,i+2,true,k-1);
            }
        }
        else{
            if(i+1<v.size()){
                if(v[i+1]<v[i]) b = prev - v[i] + 1 + rec(v,i+2,true,k-1);
                else b = prev - v[i] + 1 +  + v[i+1] - v[i] + 1 + rec(v,i+2,false,k-1);
            }
            else{
                b = prev - v[i] + 1 + rec(v,i+2,true,k-1);
            }
        }
        
        
        nb = rec(v,i+1,true,k);
    }
    return dp[check][k][i] = min(b,nb);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    if(n==1){
        cout<<0<<endl;
        return;
    }
    memset(dp,-1LL,sizeof(dp));
    int k = (n+1)/2;
    for (int i = 1; i <= k; i++)
    {
        cout<<rec(v,0,false,i)<<" ";    
    }
    cout<<endl;
    
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
