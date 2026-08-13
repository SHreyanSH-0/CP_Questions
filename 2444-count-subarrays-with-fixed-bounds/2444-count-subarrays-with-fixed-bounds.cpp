class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        for(int i=0;i<nums.size();i++){
            int l = i;
            int mini = 1e8;
            int maxi = -1e8;
            while(i < nums.size() && nums[i] >= minK && nums[i]<=maxK){
                
                mini = min(mini, nums[i]);
                maxi = max(maxi, nums[i]);

                i++;
                
            }

            if(mini != minK || maxi != maxK) continue; 

            int r = i-1;

            if(r < l) continue;

            queue<int> q1, q2;
            int hold = 0;
            for(int j=l;j<=r;j++){
                if(nums[j] == minK) q1.push(j);
                if(nums[j] == maxK) q2.push(j);
            }

            for(int j=l;j<=r;j++){
                while(!q1.empty() && q1.front() < j) q1.pop();
                while(!q2.empty() && q2.front() < j) q2.pop();
                if(!q1.empty() && !q2.empty()){
                // cout<<j<<" "<<q1.front()<<" "<<q2.front()<<" "<<r<<endl;
                    ans += r - max(q2.front(), q1.front()) + 1;
                }
            }
        }

        return ans;
    }
};