class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int len = 1e8;
        for(int i=0;i<s.size();i++){
            int ones = 0;
            if(s[i] == '0') continue;
            for(int j=i;j<s.size();j++){
                if(s[j] == '1') ones++;
                if(ones > k) break;
                if(ones == k){
                    len = min(len, j-i+1);
                } 
            }
        }
        for(int i=0;i<s.size();i++){
            int ones = 0;
            string curr = "";
            if(s[i] == '0') continue;
            for(int j=i;j<s.size();j++){
                curr.push_back(s[j]);
                if(s[j] == '1') ones++;
                if(ones > k) break;
                if(ones == k && len == curr.size()){
                    if(ans == "") ans = curr;
                    ans = min(ans, curr);

                } 
            }
        }

        return ans;
    }
};