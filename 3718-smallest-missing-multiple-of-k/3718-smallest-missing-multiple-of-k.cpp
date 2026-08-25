class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = k;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0&&ans==nums[i]){
                ans+=k;
            }
        }
        return ans;
    }
};