class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        bool inc = true, dec = true;
        char mini = 'z';
        char maxi = 'a';
        int miniInd = -1;
        int maxiInd = -1;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size()&&s[i]>s[i+1]){
                inc = false;
            }
            if(i+1<s.size()&&s[i]<s[i+1]){
                dec = false;
            }
            if(mini>s[i]){
                mini = s[i];
                miniInd=i;
            }
            if(maxi<=s[i]) {maxi = s[i]; maxiInd = i;}
        }
        if(inc) return 0;
        if(s.size()==2&&dec) return -1;
        if(mini == s[0]||maxi==s[s.size()-1]) return 1;
        if(miniInd==s.size()-1&&maxiInd==0) return 3;
        return 2;
    }
};