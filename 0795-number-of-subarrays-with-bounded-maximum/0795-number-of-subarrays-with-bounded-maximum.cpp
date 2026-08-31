class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        long long n = nums.size();
        long long ans = (n*(n+1))/2;
        int prev = -1;
        for(int i=0;i<n;i++){
            if(nums[i] < left){
                int ct = 0;
                while(i < n && nums[i] < left) {
                    ct++;
                    i++;
                }

                ans -= (ct*(ct+1))/2;
            }
            if(i<n && nums[i] > right){
                long long a = i - prev;
                long long b = n - i;
                cout<<a<<" "<<b<<endl; 
                ans -= a*b ;
                prev = i;
            }
        }

        return ans;
    }
};