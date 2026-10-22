class Solution {
public:

    int fun(vector<int> &nums){
        vector<int> v1;
        int idx = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                idx = i;
                break;
            }
        }

        for(int i=idx;i<nums.size();i++) v1.push_back(nums[i]);
        for(int i=0;i<idx;i++) v1.push_back(nums[i]);

        int ans = 1e8;

        bool check = true;

        for(int i=0;i<nums.size()-1;i++){
            if(v1[i]>v1[i+1]) check = false;
        }
        if(check) ans = min(ans,idx);
        
        check = true;
        for(int i=1;i<nums.size()-1;i++){
            if(v1[i]<v1[i+1]) check = false;
        }
        if(check) ans = min(ans, idx + 2);

        if(ans==1e8) return -1;
        return ans;
    }
    
    int minOperations(vector<int>& nums) {
        int ans = fun(nums);
        reverse(nums.begin(),nums.end());
        int ans2 = fun(nums);
        
        if(ans==-1&&ans2==-1) return -1;
        return min(ans,ans2+1);
    }
};