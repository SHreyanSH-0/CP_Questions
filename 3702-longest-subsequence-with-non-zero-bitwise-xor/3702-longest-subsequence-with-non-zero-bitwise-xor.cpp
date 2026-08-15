class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        int zero = 0;
        int x = 0;
        for(int i=0;i<nums.size();i++){
            x = x^nums[i];
            if(nums[i]==0) zero++;
        }

        if(zero == nums.size()) return 0;

        if(x != 0) ans = nums.size();
        else{
            ans = nums.size() - 1;
        }
        return ans;
    }
};