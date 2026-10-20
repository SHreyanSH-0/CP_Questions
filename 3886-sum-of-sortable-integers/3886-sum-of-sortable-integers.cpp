class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        vector<int> factor;
        int n = nums.size();

        for(int i=1;i<=n;i++) if(n%i==0) factor.push_back(i);
        int ans = 0;
        for(int i=0;i<factor.size();i++){
            int cur = factor[i];
            int prev = -1;
            bool check = true;
            vector<int> hold(cur);
            for(int j=0;j<n;j++){
                int mini = INT_MAX;
                int minidx = -1;
                int maxi = -1;
                int maxidx = -1;
                int k;
                for(k=j;k<j+cur&&k<n;k++){
                    hold[k-j] = (nums[k]);
                }
                j = k-1;

                for(int k=0;k<hold.size();k++){
                    if(mini>hold[k]){
                        mini = hold[k];
                        minidx = k;
                    }
                    if(maxi<=hold[k]){
                        maxi = hold[k];
                        maxidx = k;
                    }
                }
                int inc = 1;
                if(minidx>maxidx){
                    int ct = (minidx-maxidx-1);
                    int ct1 = 0, ct2 = 0;
                    for(int k=maxidx+1;k<minidx;k++){
                        if(hold[k]==mini) ct1++;
                        if(hold[k]==maxi) ct2++;;
                    } 
                    if(ct1!=ct&&ct2!=ct) inc = 0;
                    for(int k=0;k<maxidx-1;k++) if(hold[k]>hold[k+1]) inc = 0;
                    for(int k=minidx;k<cur-1;k++) if(hold[k]>hold[k+1]) inc = 0;
                    if(hold[cur-1]>hold[0]) inc = 0;
                }
                else
                { 
                    int ct = cur - (maxidx-minidx+1);
                    int ct1 = 0, ct2 = 0;
                    for(int k=0;k<minidx;k++) {
                        if(hold[k]==mini) ct1++;
                        if(hold[k]==maxi) ct2++;;
                    } 
                    for(int k=maxidx+1;k<cur;k++) {
                        if(hold[k]==mini) ct1++;
                        if(hold[k]==maxi) ct2++;;
                    } 
                    if(ct1!=ct&&ct2!=ct) inc = 0;
                    for(int k=minidx;k<maxidx-1;k++){
                        if(hold[k]>hold[k+1]) inc = 0;
                    }
                }

                
                if((!inc)||prev>mini) {
                    check = false;
                    break;
                }
                prev = maxi;
                
            }
            if(check) ans += cur;
        }
        return ans;
    }
};