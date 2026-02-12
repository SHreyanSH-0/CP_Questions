#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int idx,int k,vector<int>& arr,vector<vector<int>>& dp){
    if(idx>=arr.size()) return 0;
    if(dp[idx][k]!=-1) return dp[idx][k];
    int ans=1e15;
    int m = arr[idx];
    for(int i=1;i<=min(k+1,(int)arr.size()-idx);i++){
        m = min(m,arr[idx + i-1]);
        ans=min(ans,m*i+recur(idx+i,k-i+1,arr,dp));
    }
    return dp[idx][k]=ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<int>> dp(n+1,vector<int>(k+2,-1));
        cout<<recur(0,k,arr,dp)<<endl;
    }
}