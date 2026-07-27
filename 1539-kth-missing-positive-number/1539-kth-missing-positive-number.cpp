class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1, mid;
        int missing;

        while(low<=high){
            mid = (high + low)/2;
            missing = arr[mid] - mid-1;
            if(missing<k){
                low = mid+1;
            }
            else
                high = mid-1;
            
        }
        cout<<low<<" "<<high<<endl;
        return  k - ( - high - 1);// or low + k ;
    }
};