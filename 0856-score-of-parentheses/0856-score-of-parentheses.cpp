class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int ans = 0;
        for(auto c : s){
            
            int curr = c == '(' ? -1 : 0;
            
            if(st.empty() || curr == -1) st.push(curr);
            else{
                int top = st.top();
                int val = 1;
                if(top != -1){
                    val = 2*top;
                    st.pop();
                    top = st.top();
                }
                st.pop();

                if(st.empty()){
                    ans += val;
                }
                else if(st.top()!=-1){
                    val += st.top();
                    st.pop();
                    st.push(val);
                }
                else{
                    st.push(val);
                }
            }
        }

        while(!st.empty()) {
            cout<<st.top()<<" ";
            st.pop();
        }
        return ans;
    }
};