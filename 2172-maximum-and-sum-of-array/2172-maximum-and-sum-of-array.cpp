int dp[9][3][1<<18];
class Solution {
public:
    int rec(vector<int>& nums, int slot,int i, int taken, int bit_mask){
        if(i >= slot) return ((1<<nums.size()) - 1 == bit_mask) ? 0 : -1e8;
        if(dp[i][taken][bit_mask]!=-1) return dp[i][taken][bit_mask];
        // cout<<i<<" "<<taken<<" "<<bit_mask<<endl;
        int ans = rec(nums,slot,i+1,0,bit_mask);
        int curr_slot = i+1;
        if(taken != 2){
            for(int j=0;j<nums.size();j++){
                if(bit_mask & (1<<j) ) continue;
                ans = max(ans,(curr_slot & nums[j]) + rec(nums,slot,i,taken+1,bit_mask | (1<<j)));
                // ans = max(ans,(curr_slot & nums[j]) + rec(nums,slot,i+1,0,bit_mask | (1<<j)));
            }
        } 

        return dp[i][taken][bit_mask]=ans;
    }

    int maximumANDSum(vector<int>& nums, int numSlots) {
        int ans = 0;

        memset(dp,-1,sizeof(dp));
        
        ans = rec(nums,numSlots,0,0,0);

        return ans;
    }
};