class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& e, string s, int k) {
        vector<vector<pair<int,int>>> v(n);
        for(int i=0;i<e.size();i++){
            v[e[i][0]].push_back({e[i][1],e[i][2]});
        }

        priority_queue<pair<pair<int,int>,pair<char,int>>, vector<pair<pair<int,int>,pair<char,int>>>, greater<pair<pair<int,int>,pair<char,int>>>> pq;
        // {{cost,currK}, {prev, node}}
        pq.push({{0,1},{s[0],0}});
        // vector<vector<vector<int>>> dist(n,vector<vector<int>>(k+1, vector<int>(26,1e9)));
        unordered_map<long long,int> dist;
        long long start = (0LL<<20) | (1LL<<10) | (s[0]-'a');
        dist[start] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long node = it.second.second;
            char prev = it.second.first;
            int currK = it.first.second;
            int cost = it.first.first;
            long long hold = (node<<20 | currK<<10 | (prev-'a') );
            if(dist.find(hold)!=dist.end() && dist[hold] < cost) continue;
            if(node==n-1) return cost;

            for(auto&[to,w] : v[node]){
                if(prev==s[to]){
                    hold = ((long long)to<<20 | (currK + 1)<<10 | (prev-'a'));
                    if(currK + 1 <= k && (!dist.count(hold) || dist[hold] > w + cost)){
                        dist[hold] = w + cost;
                        pq.push({{dist[hold] ,currK + 1}, {prev, to}});
                    }
                }
                else{
                    hold = ((long long)to<<20 | (1)<<10 | (s[to]-'a'));
                    if(!dist.count(hold)||dist[hold] > w + cost){
                        dist[hold] = w + cost;
                        pq.push({{dist[hold],1}, {s[to], to}});
                    }
                }
            }
        }

        return -1;
    }
};