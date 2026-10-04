class Solution {
public:
    long long dp[100000][2][2][2];
    bool dp2[100000][2][2][2];
    long long rec(vector<int>& nums, int i, int skip , int start, int odd){
        if(i >= nums.size()) return start?0:-1e9;
        long long ans = -1e9;
        if(dp2[i][skip][start][odd]) return dp[i][skip][start][odd];
        if(!start){
            ans = nums[i] + rec(nums,i+1,skip,1,1);
            ans = max(ans,rec(nums,i+1,skip,0,0));
        }
        else{
            ans = 0;
            if(skip) ans = rec(nums,i+1,0,1,odd);
            int hold = odd == 1 ? - nums[i] : nums[i];
            ans = max(ans,hold + rec(nums,i+1,skip,1,(odd+1)%2));
        }
        // cout<<i<<" "<<ans<<endl
        dp[i][skip][start][odd]=ans; 
        dp2[i][skip][start][odd]=true; 

        return ans;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp2,false,sizeof(dp2));
        return rec(nums,0,1,0,0);
    }
};