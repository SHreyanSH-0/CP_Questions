class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        int maxi = -1;
        string ans;

        for(int i=0;i<n;i++){
            if(freq[target[i]-'a'] > 0){
                for(char c = 'a';c<='z';c++){
                    if(c > target[i] && freq[c - 'a'] > 0){
                        maxi = i;
                        break;
                    }
                }
                freq[target[i]-'a']--;
            }
            else{
                for(char c = 'a';c<='z';c++){
                    if(c > target[i] && freq[c - 'a'] > 0){
                        maxi = i;
                        break;
                    }
                }
                break;
            }
        }

        if(maxi == -1) return "";

        freq = vector<int>(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<maxi;i++){
            ans.push_back(target[i]);
            freq[target[i] - 'a']--;
        }

        for(int i=0;i<26;i++){
            if(target[maxi] < i + 'a' && freq[i] > 0){
                ans.push_back(i + 'a');
                freq[i]--;
                break;
            }
        }

        for(int i=0;i<26;i++){
            while(freq[i] > 0){
                ans.push_back('a' + i);
                freq[i]--;
            }
        }

        return ans;

    }
};