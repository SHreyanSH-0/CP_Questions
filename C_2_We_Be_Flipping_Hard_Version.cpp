#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(vector<int>&v, int i,int ct,int started,vector<vector<vector<int>>> &dp,vector<vector<vector<int>>> &track){
    if(i<0) return 0;
    if(dp[i][ct][started]!=LLONG_MAX) return dp[i][ct][started];
    int p = -1e12, np = -1e12;

    if(v[i]>0){
        if(ct==0){
            //v[i] positive
            p = -v[i] + rec(v,i-1,(ct+1)%2, 1,dp,track);
            np = v[i] + rec(v,i-1,ct,started,dp,track);

            if(p>np) track[i][ct][started] = 1;
            else track[i][ct][started] = 0;
        }
        else{
            // v[i] negative
            np = -v[i] + rec(v,i-1,ct,started,dp,track);
            p = v[i] + rec(v,i-1,0,1,dp,track);

            if(p>np) track[i][ct][started] = 2;
            else track[i][ct][started] = 0;
        }
    }
    else{
        if(ct==0){
            // v[i] negative

            np = v[i] + rec(v,i-1,ct,started,dp,track);

            if(started==1){
                p = -v[i] + rec(v,i-1,1,started,dp,track);
            }
            if(p>np) track[i][ct][started] = 2;
            else track[i][ct][started] = 0;
        }
        else{
            // v[i] positive

            p = v[i] + rec(v,i-1,0,started,dp,track);
            np = -v[i] + rec(v,i-1,ct,started,dp,track); 

            if(p>np) track[i][ct][started] = 1;
            else track[i][ct][started] = 0;
        }
    }
    return dp[i][ct][started] = max(p,np);
}



void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,LLONG_MAX)));
    vector<vector<vector<int>>> track(n,vector<vector<int>>(2,vector<int>(2,-1)));
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    rec(v,n-1,0,0,dp,track);

    vector<int> ans;

    // for (int i = n-1; i >=0; i--)
    // {   
    //     cout<<i+1<<": ";
    //     for(int j=0;j<2;j++){
    //         for(int k=0;k<2;k++){
    //             cout<<track[i][j][k]<<" ";
    //         }
    //     }
    //     cout<<"--";
    //     for(int j=0;j<2;j++){
    //         for(int k=0;k<2;k++){
    //             cout<<dp[i][j][k]<<" ";
    //         }
    //     }
        
    //     cout<<endl;
    // }
    int ct = 0, started = 0;
    for (int i = n-1; i >=0; i--)
    {   
        int val = track[i][ct][started];
        // cout<<val<<endl;
        if(val==0 || val==-1){
            continue;
        }
        else if(val==1){
            started = 1;
            ct = (ct+1)%2;
            ans.push_back(i+1);
        }
        else{
            ct = (ct+1)%2;
            int hold = ans.back();
            ans.pop_back();
            ans.push_back(i+1);
            ans.push_back(hold);
        }
    }

    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    

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
