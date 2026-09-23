class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int j = 0;
        int ans = 1e8;

        int n = nums.size();
        int forward = 0;
        for(int i=0;i<n;i++){
            forward += nums[i];
        }
        if(forward == x) return n;
        // (-b-)(j------i)(--a--)
        unordered_map<int,int> map;
        int sum = 0;
        map[0] = -1;
        for(int i=0;i<n;i++){
            forward -= nums[i];
            sum += nums[i];
            int b = x - forward;

            int f = sum - b;

            // cout<<i << " "<<b<<" "<<f<< " "<<forward<<endl;

            if(map.find(b) != map.end()) {
                ans = min(ans, n - i + map[b]);
            }

            map[sum] = i;
        }

        return ans == 1e8 ? -1 : ans;
    }
};