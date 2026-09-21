class Solution {
public:
    long long dp[100000][5][2];

    long long rec(vector<int>& nums, int i,int op, int mod, int x, int k){
        if(i >= nums.size()) return x == mod && op == 1;
        long long ans = 0;
        if(dp[i][mod][op]!=-1) return dp[i][mod][op];
        if(op == 0){
            ans += rec(nums,i+1,0,mod,x,k);
            ans += rec(nums,i+1,1,nums[i]%k,x,k);
        }
        else if(op == 1){
            ans += rec(nums,i+1,1,((long long)mod*nums[i])%k,x,k);
            ans += rec(nums,nums.size(),1,mod,x,k);
        }
        return dp[i][mod][op]=ans;
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long >ans;

        // logic

        for(int i=0;i<k;i++){
            memset(dp,-1,sizeof(dp));
            ans.push_back(rec(nums,0,0,0,i,k));
        }

        return ans;
    }
};