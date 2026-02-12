#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>s>>n;
    int size = s.size();
    int ct = 0;
    int m = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if(n<=size) {
            break;
        }
        ct++;
        m += (s.size() - i + 1);
        size += s.size() -i;
    }
    n -= m;

    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if(st.empty()) {
            st.push(s[i]);
            continue;
        }
        while(!st.empty()&&ct>0&&st.top()>s[i]) {
            st.pop(); 
            ct--; 
        }
        st.push(s[i]);
    }
    string hold;

    while(!st.empty()&&ct>0){
        ct--;
        st.pop();
    }
    while(!st.empty()){
        hold.push_back(st.top());
        st.pop();
    }
    reverse(hold.begin(),hold.end());
    // cout<<hold<<" "<<n<<endl;
    cout<<hold[n-1];
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
