class Solution {
public:
    int dp[21][21];
    bool f(string &s,string &p,int i,int j,int &n,int &m){
        if(i==n && j==m)return true;
        if(j==m)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        if(j+1<m && p[j+1]=='*'){
            for(int k=i;k<=n;k++){
                if(f(s,p,k,j+2,n,m)){
                    return dp[i][j]=true;
                }
                if(s[k]==p[j] || p[j]=='.')continue;
                break;  
            }
            return dp[i][j]=false;
        }
        else if(i==n){
            return dp[i][j]=false;
        }
        else if(p[j]=='.'){
            return dp[i][j]=f(s,p,i+1,j+1,n,m);
        }
        else if(s[i]==p[j]){
            return dp[i][j]=f(s,p,i+1,j+1,n,m);
        }
        else{
            return dp[i][j]=false;
        }
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        int m=p.size();
        return f(s,p,0,0,n,m);
    }
};