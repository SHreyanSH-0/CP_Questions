class comp {
public:
    bool operator()(pair<int,int>&a, pair<int,int>&b){
        return a.first*b.second < b.first*a.second;
    }
};

class Solution {
public:

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> ans;

        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;

        int n = arr.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push({arr[i],arr[j]});
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }

        ans.push_back(pq.top().first);
        ans.push_back(pq.top().second);

        return ans;
    }
};