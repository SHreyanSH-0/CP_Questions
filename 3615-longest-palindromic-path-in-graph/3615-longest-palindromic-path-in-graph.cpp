class Solution {
public:
    int dp[14][14][1<<14];
    int rec(vector<vector<int>> &v, int node1, int node2, int vis,string &label){
        int ans = 0;
        if(dp[node1][node2][vis]!=-1) return dp[node1][node2][vis];
        // cout<<node1<<" "<<node2<<"-----------\n";
        for(auto&it1 : v[node1]){
            for(auto&it2 : v[node2]){
                if(label[it1] == label[it2] && !(vis&(1<<it1)) && !(vis&(1<<it2))  && it1 != it2){
                // cout<<it1<<" "<<it2<<endl;
                    ans = max(ans, 2 + rec(v,it1,it2,vis | (1<<it1) | (1<<it2),label));
                }
            }
        }

        return dp[node1][node2][vis]=ans;
    }

    int maxLen(int n, vector<vector<int>>& edges, string label) {
        vector<vector<int>> v(n);

        for(auto &it : edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        // odd len
        int ans = 1;
        int vis = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            vector<int> &hold = v[i];

            int len = hold.size();
            vis = (1<<i);
            for(int j=0;j<len;j++){
                for(int k=j+1;k<len;k++){
                    if(label[hold[j]] == label[hold[k]]){
                        vis = vis | (1<<hold[j]) | (1<<hold[k]);
                        ans = max(ans, 3 + rec(v,hold[j],hold[k],vis,label));
                        vis = vis ^ (1<<hold[j]) ^ (1<<hold[k]);
                    }
                }
            }
            vis = 0;
        }

        //even len
        // cout<<"even"<<endl;
        for(int i=0;i<edges.size();i++){
            
            if(label[edges[i][0]] == label[edges[i][1]]){
                vis = vis | (1<<edges[i][0]) | (1<<edges[i][1]);
                ans = max(ans, 2 + rec(v,edges[i][0],edges[i][1],vis,label));
                // cout<<ans<<endl;
                vis = vis ^ (1<<edges[i][0]) ^ (1<<edges[i][1]);
            }
            // cout<<"\n";
        }


        return ans;
    }
};