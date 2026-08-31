class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> vp;
        for(int i=lo;i<=hi;i++){
            int hold = i;
            int curr = 0;
            while(hold > 1){
                if(hold%2==1) hold = 3*hold + 1;
                else hold = hold/2;
                curr++;
            }
            vp.push_back({curr,i});
        }

        sort(vp.begin(),vp.end());

        return vp[k-1].second;
    }
};