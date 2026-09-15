class Solution {
public:
    int dp[2000];
    int rec(int i, int k, int n, vector<vector<bool>> &v){
        if(i >= n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = rec(i+1,k,n,v);
        for(int j=i;j<n;j++){
            if(j - i + 1 >= k && v[i][j]){
                ans = max(ans , 1 + rec(j+1,k,n,v));
            }
        }
        return dp[i] =ans;
    }


    int maxPalindromes(string s, int k) {

        int n = s.size();
        int ans;
        vector<vector<bool>> v(n , vector<bool>(n,false));

        for(int i=0;i<n;i++){
            int l = i - 1, r = i + 1;
            v[i][i] = true;
            while(l >= 0 && r < n && s[l] == s[r]){
                v[l][r] = true;
                l--;
                r++;
            }

            l = i - 1, r = i;

            while(l >= 0 && r < n && s[l] == s[r]){
                v[l][r] = true;
                l--;
                r++;
            }
        }
        memset(dp,-1,sizeof(dp));
        ans = rec(0,k,s.size(),v);
        return ans;
    }
};