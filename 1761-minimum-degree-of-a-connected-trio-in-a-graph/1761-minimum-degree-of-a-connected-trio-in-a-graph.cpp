class Solution {
public:
    int minTrioDegree(int n1, vector<vector<int>>& edges) {
        int n = edges.size();
        int ans = 1e8;
        vector<int> degree(n1+1,0);
        vector<vector<int>> v(n1+1, vector<int>(n1+1,0));
        for(auto it :edges){
            degree[it[0]]++;
            degree[it[1]]++;
            v[it[0]][it[1]] = 1;
            v[it[1]][it[0]] = 1;
        }
        for(int i=1;i<=n1;i++){
            for(int j=i+1;j<=n1;j++){
                for(int k=j+1;k<=n1;k++){
                    if(v[i][j] & v[j][k] & v[k][i]) ans= min(ans, degree[i] + degree[j] + degree[k]-6);
                }
                
            }
        }

        if(ans==1e8) ans = -1;

        return ans;
    }
};