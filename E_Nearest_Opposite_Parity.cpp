#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }

    map<int,vector<int>> map;
    for(int i=0;i<n-1;i++){
        map[nums[i]].push_back(i);
    }
    int ans = 1e8;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(nums.size(),1e8);
    vis[n-1] = 0;
    pq.push({0,n-1});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int num = nums[it.second];
        int step = it.first;
        if(step>vis[it.second]) continue;
        int l = sqrt(num);
        if(it.second - nums[it.second]>=0&&vis[it.second-nums[it.second]]>step+1) {
            vis[it.second-nums[it.second]]=step+1;
            pq.push({step+1,it.second-nums[it.second]});
        }
        if(it.second + nums[it.second]<n&&vis[it.second+nums[it.second]]>step+1) {
            vis[it.second+nums[it.second]]=step+1;
            pq.push({step+1,it.second+nums[it.second]});
        }
    }

    for (int i = 0; i < n; i++)
    {
        
    }
    
    
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
