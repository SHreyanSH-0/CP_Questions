class Solution {
public:
    int dp[2000000];
    int rec(int bit, int maxi, int total){
        int hold = bit;
        int sum = 0;
        int curr = 1;
        int ct = 0;
        while(hold > 0){
            if(hold%2==1) sum += curr, ct++;
            curr++;
            hold/=2;
        }

        if(sum >= total){
            return ct%2==0 ? false : true;
        }

        if(dp[bit] != -1) return dp[bit];

        bool ans = true;
        if(ct%2==0){
            ans = false;
            for(int i=0;i<maxi;i++){
                if(bit & (1<<i)) continue;
                ans = ans | rec(bit | (1<<i), maxi, total);
            }
        }
        else{
            ans = true;
            for(int i=0;i<maxi;i++){
                if(bit & (1<<i)) continue;
                ans = ans & rec(bit | (1<<i), maxi, total);
            }
        }

        return dp[bit] = ans;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal==0) return true;
        if(desiredTotal > (maxChoosableInteger*(maxChoosableInteger+1))/2) return false;
        memset(dp,-1,sizeof(dp));
        return rec(0,maxChoosableInteger,desiredTotal);
    }
};