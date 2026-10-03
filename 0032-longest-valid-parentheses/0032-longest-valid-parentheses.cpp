class Solution {
public:
    int longestValidParentheses(string s) {
        if(s=="")
        return 0;
        stack<pair<char, int>> a;
        stack<pair<int, int>> hold;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (a.empty()) {
                a.push({s[i], i});
                continue;
            }

            if (a.top().first == '(' && s[i] == ')') {
                if (hold.empty())
                    hold.push({a.top().second, i});
                else {
                    pair<int,int> p = {a.top().second, i};
                    while(!hold.empty()&&(hold.top().second + 1 == p.first|| p.first < hold.top().first))
                    {    
                        if (hold.top().second + 1 == p.first) {
                            int h = hold.top().first;
                            p = {h, i};
                            hold.pop();
                        } else if (p.first < hold.top().first) {
                            hold.pop();
                            p = {p.first, i};
                        }
                    }
                    hold.push({p.first, p.second});

                }
                a.pop();
                continue;
            }

            a.push({s[i], i});
        }
        while (!hold.empty()) {
                        cout << hold.top().first << '-' << hold.top().second << "\n";
            // if (hold.top().second + 1 == p.first){
            //     int h = hold.top().first; 
            //     hold.pop();
            //     hold.push({h,p.second});
            //     p = hold.top();
            // }
            // if(hold.top().second==p.first-1){
            //     ans += hold.top().second - hold.top().first + 1;
            //     p = hold.top();
            //     hold.pop();
            //     continue;
            // }
            // cout << hold.top().first << '-' << hold.top().second << "\n";
            
            if(ans<hold.top().second - hold.top().first + 1){
                ans = hold.top().second - hold.top().first + 1;
                // p = hold.top();
            }
            hold.pop();
        }
        return ans;
    }
};