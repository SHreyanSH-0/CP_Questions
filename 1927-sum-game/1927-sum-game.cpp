class Solution {
public:
    bool sumGame(string num) {
        bool ans = false;
        int left = 0, right = 0;
        int l = 0, r = 0;

        for(int i=0;i<num.size()/2;i++){
            if(num[i] == '?') l++;
            else left += num[i]- '0';
        }
        for(int i=num.size()/2;i<num.size();i++){
            if(num[i] == '?') r++;
            else right += num[i] - '0';
        }

        // left + l = right + r
        // l - r = right - left
        // l - r = 5 - 14
        // 1l - 3r = -9
        // 3r - 1l = 9

        int a = (l+r+1)/2;
        int b = (l+r)/2;
        cout<<left<<" "<<l<<" "<<right<<" "<<r<<endl;
        if(left == right){
            // l - r = 0
            if(l > r || r > l) ans = true;
        }   
        else if(left > right){
            // r - l = left - right
            if(l >= r) ans = true;
            else{
                int hold = r - l;
                if((hold+1)/2 * 9 > left - right || hold/2 * 9 < left - right) ans = true;
            }
        }
        else{
            // l - r = right - left
            if(l <= r) ans = true;
            else{
                int hold = l - r;
                if((hold+1)/2 * 9 > right - left || hold/2*9 < right - left) ans = true;
            }
        }

        return ans;
    }
};