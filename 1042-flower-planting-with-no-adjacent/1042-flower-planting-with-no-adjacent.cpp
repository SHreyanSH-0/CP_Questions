class Solution {
public:
    void dfs(int u,vector<vector<int>>&adj,vector<int>&vis){
        set<int> st;
        for(int i:adj[u]){
            st.insert(vis[i]);
        }
        for(int i=1;i<=4;i++){
            if(st.find(i)==st.end() && !vis[u]){
                vis[u]=i;
                for(int v: adj[u]){
                    if(!vis[v]){
                        dfs(v,adj,vis);
                    }
                }
            }
        }
        
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(int i=0;i<paths.size();i++){
            int u= paths[i][0]-1,v= paths[i][1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }

        return vis;

    }
};