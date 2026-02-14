#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void rec(vector<int> &nums, int n, int i, vector<int>&ans, int sum){
    if(i>=n){
        ans.push_back(sum);
        return;
    }
    rec(nums,n,i+1,ans,sum+nums[i]);
    rec(nums,n,i+1,ans,sum);
}

void solve()
{
    int n,goal;
    cin>>n>>goal;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    int mid = nums.size()/2;
    vector<int> a, b;
    rec(nums,mid,0,a,0);
    rec(nums,nums.size(),mid,b,0);
    sort(b.begin(),b.end());
    int ans = 0;
    for(int i=0;i<a.size();i++){
        int hold = goal - a[i];
        int ind1 = lower_bound(b.begin(),b.end(),hold) - b.begin();
        int ind2 = upper_bound(b.begin(),b.end(),hold) - b.begin();
        ans += (ind2 - ind1);
    }
    cout<< ans;
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
