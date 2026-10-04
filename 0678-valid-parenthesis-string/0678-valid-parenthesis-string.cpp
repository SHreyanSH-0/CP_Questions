class Solution {
public:
    bool checkValidString(string s) {
        for(int i=1;i<s.size();i++){
            if(s[i]==')'){
                for(int j=i-1;j>=0;j--){
                    if(s[j]=='('){
                        s[i]='_';
                        s[j] ='_';
                        break;
                    }
                }

            }
        }


        stack<char> st;
        cout<<s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='_'){
                continue;
            }
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            else if(st.top()=='*'&&s[i]==')'){
                st.pop();
                continue;
            }
            else if(st.top()=='('&&s[i]=='*'){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }

        while(!st.empty()){
            if(st.top()!='*')
            return false;
            st.pop();
        }

        return true;
    }
};