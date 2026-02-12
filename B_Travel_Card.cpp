/*
   Author: SONIT RAJ
    created: 23:26:28 27-10-2025
*/


#include<bits/stdc++.h>
using namespace std;
// ╭──────────────────────────────╮
// │      GLOBAL ZONE             │
// ╰──────────────────────────────╯
// ALWAYS USE cout << FIXED << SETPRECISION(value) <<NUMBER; WHILE OUTPUTTING FLOATS
// const int max_n = 1e7 + 3;
// int dp[max_n];



// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<int>t(n);
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    vector<int>dp(n,1e9);
    dp[0]=20;
    dp[1]=40;
    for(int i=2;i<n;i++){
        int r=t[i]-90+1;
        auto it=lower_bound(t.begin(),t.end(),r);
        int idx=it-t.begin();
        int r2=t[i]-1440+1;
        auto it2=lower_bound(t.begin(),t.end(),r2);
        int idx2=it2-t.begin();
        dp[i]=dp[i-1]+20;
        if(idx<i){
            dp[i]=min(dp[i],dp[idx]+50);
        }
        if(idx2<i){
            dp[i]=min(dp[i],dp[idx2]+120);
        }
    }
    for(int i=0;i<n;i++){
        if(i){
            cout<<dp[i]-dp[i-1]<<endl;
        }
        else{
            cout<<dp[i]<<endl;
        }
    }



}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    while(_--){
        solve();
    }
}