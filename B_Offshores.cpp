#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int i,bool flag,vector<int>& arr,int& x,int& y,vector<vector<int>>& dp){
    if(i==arr.size()) return flag?0:-1e15;
    if(dp[flag][i]!=-1) return dp[flag][i];
    if(!flag){
        int f=(arr[i]/x)*y+recur(i+1,false,arr,x,y,dp);
        int t=arr[i]+recur(i+1,true,arr,x,y,dp);
        return dp[flag][i]=max(f,t);
    }
    else return dp[flag][i]=(arr[i]/x)*y+recur(i+1,flag,arr,x,y,dp);

}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<int>> dp(2,vector<int>(n+1,-1));
        cout<<recur(0,0,arr,x,y,dp)<<endl;
    }
}