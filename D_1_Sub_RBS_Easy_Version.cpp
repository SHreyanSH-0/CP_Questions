#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    vector<int> open(n), close(n);
    int o = 0, c = 0;
    stack<int> st;
    for(int i=0;i<n;i++){
        if(s[i]=='(') {o++;}
        else c ++;
        open[i] = o;
        close[i] = c;

    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='(') st.push(i);
    }
    int ans = -1;
    o = 0;
    for (int i = 0; i < n; i++)
    {
        if(!st.empty()&&i==st.top()) st.pop();
        if(s[i]==')'){
            int start = i;
            int end = 1e8;
            if(!st.empty()) end = st.top();
            else continue;
            if(open[n-1] - open[end]>= end - start){
                ans = max(ans,n-2*(end-start));
            }
        }
        
    }
    
    cout<<ans<<endl;
    
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
