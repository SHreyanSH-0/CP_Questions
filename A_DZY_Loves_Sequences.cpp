#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int rec(vector<int>& nums, int i,int change,int conti,int start,vector<vector<int>> &dp,int flag){
    if(i>=nums.size()) return 0;
    if(dp[i][change*8 + conti*4 + flag *2 + start]!=-1) return dp[i][change*8 + conti*4 + flag *2 + start];
    int p = 0;
    int np = 0;
    if(start==1){
        p = 1 + max(rec(nums,i+1,1,0,0,dp,0),rec(nums,i+1,0,1,0,dp,1));
        p = max(p, rec(nums,i+1,1,0, 1,dp,0));
        return dp[i][change*8 + conti*4 + flag *2 + start]= max(p,np);
    }
    else{
        if(conti==1){
            int ind = i - 2;
            if(ind>=0){
                if(nums[i]>nums[ind]+1||(flag==1)){
                    p = 1 + rec(nums,i+1,0,0,0,dp,0);
                }
            }
            else{
                p = 1 + rec(nums,i+1,0,0,0,dp,0);
            }
            return dp[i][change*8 + conti*4 + flag *2 + start]= max(p,np);
        }
        else{
            if(change==1){
                if(nums[i]>nums[i-1]){
                    p = 1 + max(rec(nums,i+1,1,0,0,dp,0),rec(nums,i+1,0,1,0,dp,0));
                }
                else{
                    p = 1 + rec(nums,i+1,0,1,0,dp,0);
                }
            }
            else{
                if(nums[i]>nums[i-1])
                    p = 1 +rec(nums,i+1,0,0,0,dp,0);
            }
            return dp[i][change*8 + conti*4 + flag *2 + start]= max(p,np);
        }
    }
    
}

int longestSubarray(vector<int>& nums) {
    vector<vector<int>> dp(nums.size(),vector<int>(16,-1));
    return rec(nums,0,1,0,1,dp,0);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<longestSubarray(v);
}
int main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
