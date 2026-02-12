#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define int long long
int solve(int last, vector<int>&a,vector<int>&c,vector<int>&dp){
    if(last>=a.size()-1){
        return 0;
    }
    if(dp[last]!=-1){
        return dp[last];
    }
    else{
        int ans=LLONG_MAX;
        int temp=0;
        for(int j=last+1;j<a.size();j++){
            if(a[last]<=a[j]){
                ans=min(ans,temp+solve(j,a,c,dp));
            }
            temp+=c[j];
        }
        return dp[last]=min(ans,temp);
    }
}
void so()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>c(n);
    for(int j=0;j<n;j++){
        cin>>c[j];
    }
    vector<int>dp(n,-1);
    int ans=LLONG_MAX;
    int temp=0;
    for(int i=0;i<n;i++){
        ans=min(ans,temp+solve(i,a,c,dp));
        temp+=c[i];
    }
    cout<<ans<<endl;
}
signed main() {

    ll test;
    cin>>test;
    while(test--)
    {
        so();
    }
    return 0;
}
