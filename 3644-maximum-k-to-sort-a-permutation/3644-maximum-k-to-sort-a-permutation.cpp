// class Solution {
// public:
//     int sortPermutation(vector<int>& nums) {
//         int ans = 0;

//         int n = nums.size();

//         int ct = 1;

//         for(int i=0;i<n;i++){
//             if(nums[i] < nums[i+1]){
//                 ct++;
//             }
//         }

//         if(ct == n) return 0;
        
//         if(nums[0]!= 0) return 0;


//         for(int i=1;i<n;i++){
//             int idx = i;
//             while(nums[idx] != idx){
//                 v.push_back(nums[idx]);
//                 idx = nums[idx];
//             }


//         }

//         return ans;
//     }
// };

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;  // all bits set: nothing misplaced yet
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i) {  // this number has to move
                k &= nums[i];  // keep only the bits it shares
                if (k == 0) return 0;  // bits only disappear, so 0 stays 0
            }
        return max(k, 0);  // -1 means nothing has to move
    }
};

