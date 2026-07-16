class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> g(nums.size());
        long long mx = 0;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            mx = max((long long)nums[i],mx);
            g[i] = __gcd(mx,(long long)nums[i]);
        }
        sort(g.begin(),g.end());
        int j = g.size()-1;
        int i = 0;
        while(i<j){
            ans += __gcd(g[i++],g[j--]);
        }
        return ans;
        
    }
};