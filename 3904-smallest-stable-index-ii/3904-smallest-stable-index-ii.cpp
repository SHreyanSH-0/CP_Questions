class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> hold(nums.size(),INT_MAX);
        int mini = INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            mini = min(nums[i],mini);
            hold[i] = mini;
        }
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi = max(nums[i],maxi);
            if(maxi - hold[i] <=k) return i;
        }
        return -1;
    }
};