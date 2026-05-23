#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<int>& cost, vector<int>& time, int i,int t1){
        if(i>=cost.size()) return t1>=0?0:1e15;
        if(dp[i][t1 + 2000LL]!=-1) return dp[i][t1 + 2000LL]; 
        int paid = 1e15, free = 1e15;
        paid = cost[i] + rec(cost,time,i+1,min(t1+time[i],2000LL));
        free = rec(cost,time,i+1,t1-1);
        return dp[i][t1 + 2000LL] = min(paid , free);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        dp.assign(2001, vector<int>(4005, -1));
        return rec(cost,time,0,0);
    }
};

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }
    
    Solution st;

    int ans = st.paintWalls(b,a);

    cout<<ans<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
