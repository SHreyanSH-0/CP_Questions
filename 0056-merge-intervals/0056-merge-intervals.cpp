class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;

        sort(intervals.begin(),intervals.end());

        for(int i=0;i<intervals.size();i++){
            if(merged.empty()) merged.push_back(intervals[i]);
            else{
                vector<int> prev_inter = merged.back();
                vector<int> curr_inter = intervals[i];

                if(prev_inter[1] >= curr_inter[0]){
                    prev_inter[1] = max(prev_inter[1], curr_inter[1]);
                    merged.back() = prev_inter;
                }
                else{
                    merged.push_back(curr_inter);
                }
            }
        }

        return merged;
    }
};