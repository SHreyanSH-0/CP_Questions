class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        vector<int> ans(word2.size(), -1);
        
        vector<int> hold1(word1.size(),0) , hold2(word1.size(), 0);

        int ct = 0;
        int j = 0;

        for(int i=0;i<word1.size();i++){
            if(j < word2.size()){
                if(word1[i] == word2[j]) {
                    ct++;
                    j++;
                }
            }
            hold1[i] = ct;
        }
        ct = 0;
        j = word2.size() - 1;
        for(int i= word1.size() - 1;i>=0;i--){
            if(j >= 0){
                if(word1[i] == word2[j]) {
                    ct++;
                    j--;
                }
            }
            hold2[i] = ct;
        }

        int split = -1;
        int n = word2.size();
        int prev1 = 0;
        int prev2 = 0;
        for(int i =0 ;i<word1.size();i++){
            if(i+1 < word1.size()) prev2 = hold2[i+1];
            else prev2 = 0;
            if(i > 0) prev1 = hold1[i-1];


            if(hold1[i] == prev1+1 || hold2[i] == prev2 + 1) continue;
            if(hold1[i] + hold2[i] + 1 >= n){
                split = i;
                break;
            }
        }

        if(split == -1){
            j = 0;
            for(int i=0;i<word1.size();i++){
                if(j < n && word1[i] == word2[j]){
                    ans[j] = i;
                    j++; 
                }
            }

            if(j < word2.size()) ans = {};
        }
        else{
            j = 0;
            for(int i=0;i<split;i++){
                if(j < n && word1[i] == word2[j]){
                    ans[j] = i;
                    j++; 
                }
            }
            if(j!=n){
                ans[j] = split;
                j++;

                for(int i=split+1;i<word1.size();i++){
                    if(j < n && word1[i] == word2[j]){
                        ans[j] = i;
                        j++; 
                    }
                } 
            }

        }

        // for(int i=0;i<word1.size();i++) cout<<hold1[i]<<" ";cout<<endl;
        // for(int i=0;i<word1.size();i++) cout<<hold2[i]<<" ";cout<<endl;



        return ans;
    }
};