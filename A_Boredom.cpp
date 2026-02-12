#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(vector<int> &v,vector<int> &ct,int i,vector<int> &dp){
    if(i>=v.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int p = ct[i]*v[i],np = 0;
    np = rec(v,ct,i+1,dp);
    int ind = upper_bound(v.begin(),v.end(),v[i]+1)-v.begin();
    if(ind<v.size())
    p += rec(v,ct,ind,dp);
    return dp[i] = max(p,np);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v,ct;
    map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        int hold;
        cin>>hold;
        m[hold]++;
    }

    for(auto &[x,y] : m){
        v.push_back(x);
        ct.push_back(y);
    }
    vector<int> dp(n,-1);

    cout<<rec(v,ct,0,dp);
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
