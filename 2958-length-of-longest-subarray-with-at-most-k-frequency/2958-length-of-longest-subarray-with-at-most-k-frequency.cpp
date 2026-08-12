class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int ans = 0;
        int j =0;

        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;

            if(map[nums[i]] > k){
                while(map[nums[i]] > k){
                    map[nums[j]]--;
                    if(map[nums[j]] == 0){
                        map.erase(nums[j]);
                    }
                    j++;
                }
            }

            ans = max(ans , i - j + 1);
        }

        return ans;
    }
};