class Solution {
public:
int dp[21][21][2];
    int f(vector<int>&a,int i,int j,int t){
        if(i>j)return 0;
        if(dp[i][j][t]!=-1)return dp[i][j][t];
        int ans=0;
        if(t==0){
            ans=max(a[i]+f(a,i+1,j,1-t),a[j]+f(a,i,j-1,1-t));
        }
        else{
            ans=min(f(a,i+1,j,1-t),f(a,i,j-1,1-t));
        }
        return dp[i][j][t]=ans;
    }
    bool predictTheWinner(vector<int>&a) {
        memset(dp,-1,sizeof(dp));
        int n=a.size();
        int sum=f(a,0,n-1,0);
        int total=0;
        for(int i=0;i<n;i++){
            total+=a[i];
        }
        return total-sum<=sum;
    }
};