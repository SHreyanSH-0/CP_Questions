class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sum1=(n*(2 + (n-1))),sum2=(n*(1 + (n-1)));
        return __gcd(sum1,sum2);
    }
};