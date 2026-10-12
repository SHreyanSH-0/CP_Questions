class Solution {
public:
    int MOD= 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> temp(32,0);
        for(int i=0;i<nums.size();i++){
            int x= nums[i];
            for(int j=0;j<32;j++){
                if((1<<j)&x){
                    temp[j]++;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<k;i++){
            int x=0;
            for(int j=0;j<32;j++){
                if(temp[j]){
                    temp[j]--;
                    x= x| (1<<j);
                }
            }
            ans= (ans+(long long)x*x)%MOD;
        }
        return ans;
    }
};