#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if(!st.empty()&&(s[i]=='1'&&st.top()=='0')){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    int one = 0 , zero = 0;
    while (!st.empty())
    {
        if(st.top()=='1') one++;
        else zero++;

        st.pop();
    }

    if(one>0&&zero>0){
        cout<<2<<endl;
    }
    else if(one == 0 && zero == 0) cout<<0<<endl;
    else cout<<1<<endl;
    
    
}
int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
