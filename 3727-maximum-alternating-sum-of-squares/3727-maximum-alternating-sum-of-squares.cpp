class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()/2;i++){
            ans -= nums[i];
        }

        for(int i=nums.size()/2;i<nums.size();i++){
            ans += nums[i];
        }

        return ans;
    }
};