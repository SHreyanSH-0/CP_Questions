class Solution {
public:

    // bool rec(vector<int>& nums, int ind, vector<int>& dp){
    //     if(ind>=nums.size()-1)
    //     return true;
    //     else if(nums[ind]==0) return false;

    //     if(dp[ind]!=-1) return dp[ind];

    //     for(int i = 1;i<=nums[ind];i++){
    //         if(rec(nums,ind + i,dp)){
    //             return dp[ind + i] = 1;
    //         }
    //         else{
    //             dp[i] = 0;
    //         }
    //     }
    //     return dp[ind] = 0;
    // }

    bool canJump(vector<int>& nums) {
        // vector<int> dp(nums.size(),-1);
        
        int g = nums.size() - 1;

        for(int i=nums.size() - 1; i>=0;i--){
            if(nums[i] + i >= g) g = i;
        }

        return nums[0] >= g;
        // return rec(nums,0,dp);
    }
};