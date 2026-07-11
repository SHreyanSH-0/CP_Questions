#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
bool isPal(string&s){
    int j = s.size()-1;

    for(int i=0;i<j;i++,j--){
        if(s[i]!=s[j]) return false;
    }

    return true;
}

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if(!st.empty() && st.top() == s[i]) continue;
        st.push(s[i]);
    }
    int ans = 0;
    if(st.size() > 2) cout<<1<<endl;
    else if(st.size()==1) cout<<1<<endl;
    else cout<<2<<endl;
        
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
