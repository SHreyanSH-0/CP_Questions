class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26];
        int n = s.size();
        
        for(int i=0;i<n;i++){
            freq[s[i] - 'a']++;
        }

        bool flag[26];

        for(int i=0;i<26;i++) flag[i] = false;

        stack<char> st;

        for(int i=0;i<n;i++){

            if(flag[s[i] - 'a']) {
                freq[s[i] - 'a']--;
                continue;
            }
            while(!st.empty() && st.top() >= s[i] && freq[st.top() - 'a'] > 1){
                freq[st.top() -'a']--;
                flag[st.top() - 'a'] = false;
                st.pop();
            }

            flag[s[i] - 'a'] = true; 
            st.push(s[i]);
        }


        string ans = "";

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        

        reverse(ans.begin(),ans.end());

        return ans;
    }
};