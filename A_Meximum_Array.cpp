#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
vector<int> maximumMEX(vector<int>& nums) {
    int n = nums.size();

    vector<int> hold(n),ans;
    set<int>s;

    for(int i=0;i<=n;i++)s.insert(i);
    for(int i=n-1;i>=0;i--){
        if(s.find(nums[i])!=s.end())s.erase(nums[i]);
        hold[i]=*s.begin();
    }

    s.clear();
    int prev = 0;
    for(int i=0;i<=hold[prev];i++)s.insert(i);
    for(int i=0;i<n;i++){
        s.erase(nums[i]);
        int curr = *s.begin();

        if(curr>=hold[prev]){
            ans.push_back(curr);
            if(i<n-1){
                prev = i+1;
                s.clear();
                for(int j=0;j<=hold[prev];j++) s.insert(j);
            }
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> ans = maximumMEX(v);
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
