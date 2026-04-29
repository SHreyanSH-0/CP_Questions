#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007


int rec(vector<int>&v,int i,int med,vector<vector<int>>&a,vector<int>&dp){
    if(i>=v.size()){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    int ans = -1e8;
    for (int j = i; j < v.size(); j++)
    {
        if(a[i][j]==med&&(j-i+1)%2==1){
            ans = max(ans,1 + rec(v,j+1,med,a,dp));
        }
    }
    return dp[i]=ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int>v(n);
    map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        map[v[i]]++;
    }
    vector<vector<int>> a(n,vector<int>(n));
    for(int j=0;j<n;j++){
        int hold =j%2;
        priority_queue<int> maxi;
        priority_queue<int,vector<int>,greater<int>> mini;
        for (int i = j; i < n; i++)
        {
            if(maxi.empty() || v[i] <= maxi.top()){
                maxi.push(v[i]);
            } else {
                mini.push(v[i]);
            }

            if(maxi.size() > mini.size() + 1){
                mini.push(maxi.top());
                maxi.pop();
            }
            else if(mini.size() > maxi.size()){
                maxi.push(mini.top());
                mini.pop();
            }

            a[j][i] = maxi.top();

        }
        // cout<<endl;
    }

    int ans = 1;
    vector<int>dp(n,-1);
    ans = max(ans,rec(v,0,a[0][n-1],a,dp));    
    cout<<ans<<endl;
    
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
