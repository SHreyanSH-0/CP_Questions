#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int dp[100001][4][3];
int recur(int idx,int cnt,int rem,vector<int>& nums){
    if(idx==nums.size()){
        if(cnt==3&&rem==0) return 0;
        return -1e8;
    }
    if(dp[idx][cnt][rem]!=-1e9) return dp[idx][cnt][rem];
    int pick=-1e8,notpick=-1e8;
    notpick=recur(idx+1,cnt,rem,nums);
    if(cnt<3) pick=nums[idx]+recur(idx+1,cnt+1,(rem+nums[idx])%3,nums);
    return dp[idx][cnt][rem]=max(pick,notpick);
}
int maximumSum(vector<int>& nums) {
    for (int i = 0; i < 100001; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 3; k++)
                dp[i][j][k] = -1e9;    
    
    int ans= recur(0,0,0,nums);
    if(ans<0) return 0;
    return ans;
}
signed main() {

    ll test=1;
// cin>>test;
    while(test--)
    {vector<int> v = {8,7,4,3};
        cout<<maximumSum(v);
    }
    return 0;
}
