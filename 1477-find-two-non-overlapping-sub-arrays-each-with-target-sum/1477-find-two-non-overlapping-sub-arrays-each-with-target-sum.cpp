class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int ans = 1e8;
        int n = nums.size();

        vector<pair<int,int>> start;
        int j = 0, sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];

            while(j <= i && sum > target){
                sum -= nums[j++];
            }

            if(sum == target){
                start.push_back({ i - j + 1, j});
            }
        }
        if(start.size() < 2) return -1;
        vector<int> hold (n);
        int mini = 1e8;
        int last = start.size() - 1;

        for(int i = n-1; i>= 0  && last >= 0;i--){
            hold[i] = mini;
            if(start[last].second == i){
                mini = min(mini,start[last].first);
                last--;
            } 
        }

        for(int i=0;i<start.size();i++){
            int end = start[i].second + start[i].first - 1;
            ans = min(ans, start[i].first + hold[end]);
        }
        //  --j-- --i-- --j--

        if(ans == 1e8) ans = -1;
        
        return ans;
    }
};