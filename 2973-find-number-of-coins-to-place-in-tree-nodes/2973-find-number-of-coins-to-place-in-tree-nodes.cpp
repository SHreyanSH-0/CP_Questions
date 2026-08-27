class Solution {
public:
    vector<long long> merge(vector<long long>&a, vector<long long>&b){
        vector<long long> hold, ret;
        int i=0, j =0;
        while(i < 5 && j < 5){
            if(a[i] <= b[j]) hold.push_back(a[i++]);
            else hold.push_back(b[j++]);
        }
        while(i<5) hold.push_back(a[i++]);
        while(j<5) hold.push_back(b[j++]);
        for(int i=0;i<5;i++){
            ret.push_back(hold[i]);
        }
        if(hold[9] > 0){
            for(int i=9;i>=7;i--){
                ret[i-5] = hold[i];
            }
        }
        return ret;
    }

    vector<long long> rec(vector<vector<int>>& v,int node, int par, vector<int>& cost, vector<long long> &ans){
        vector<long long> ret(5,0);
        if(cost[node] > 0) ret[4] = cost[node];
        else ret[0] = cost[node];
        for(auto &it : v[node]){
            if(it == par) continue;
            vector<long long> b = rec(v,it,node,cost,ans);
            ret = merge(ret, b);
        }
        long long a = ret[0]*ret[1]*ret[4];
        long long b = ret[2]*ret[3]*ret[4];
        int ct = 0;
        for(int i=0;i<ret.size();i++) if(ret[i] == 0) ct++;
        if(ct >=3){
            ans[node] = 1;
        }
        else{
            if(a==0 && b == 0) ans[node] = 0;
            else ans[node] = max(a,b);

            if(ans[node] < 0) ans[node] = 0;
        }

        return ret;
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        vector<long long> ans(cost.size(),0);
        int n = cost.size();
        vector<vector<int>> v(n);
        for(auto&it : edges) {
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }

        rec(v,0,-1,cost,ans);

        return ans;


    }
};