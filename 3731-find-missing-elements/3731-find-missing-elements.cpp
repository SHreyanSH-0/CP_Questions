class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start = nums[0];
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(start == nums[i]) start++;
            else{
                for(int j=start;j<nums[i];j++,start++){
                    ans.push_back(start);
                }
                start++;
                
            }
        }
        return ans;
    }
};