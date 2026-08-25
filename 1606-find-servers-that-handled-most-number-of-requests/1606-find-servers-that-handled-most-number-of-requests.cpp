class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> ans;

        set<int> s;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<k;i++) s.insert(i);
        vector<int> ct(k,0);

        int time = 0;
        for(int i=0;i<arrival.size();i++){
            int time = arrival[i];

            while(!pq.empty() && pq.top().first <= time){
                s.insert(pq.top().second);
                pq.pop();
            }

            if(s.empty()) continue;

            auto it = s.lower_bound(i%k);

            if(it == s.end()) {
                pq.push({load[i] + time,*s.begin()});
                ct[*s.begin()]++;
                s.erase(s.begin());
            }
            else{
                pq.push({load[i] + time,*it});
                ct[*it]++;
                s.erase(it);
            }
        }

        int maxi = *max_element(ct.begin(),ct.end());
        for(int i=0;i<k;i++){
            if(maxi == ct[i]) ans.push_back(i);
            cout<<ct[i]<<" ";
        } 

        return ans;
    }
};