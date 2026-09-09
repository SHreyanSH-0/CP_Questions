class Solution {
public:
    long long countCommas(long long n) {
        int ans = 0;
        if(n<1000)return 0;
        else if(n<1e6) return n - 1000 + 1;
        else if(n<1e9) return 2*(n - 1e6 + 1) + (1e6 - 1000);
        else if(n<1e12) return 3*(n-1e9+1)+2*(1e9 - 1e6) + (1e6 - 1000);
        else if(n<1e15) return 4*(n-1e12+1) + 3*(1e12-1e9)+2*(1e9 - 1e6) + (1e6 - 1000);
        else return 4*(n-1e12+1) + 3*(1e12-1e9)+2*(1e9 - 1e6) + (1e6 - 1000) + 1;
    }
};