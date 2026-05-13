#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n),seg(4*(n+1),0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> hold(n,0), pg(n,0);
    int prev = v[n-1];

    
    for (int i = n-2; i>=0; i--)
    {
        if(v[i]>prev){
            hold[i] = hold[i+1] + v[i] - prev;
        } 
        else{
            hold[i] = hold[i+1];
            prev = v[i];
        }
    }
    int ans = hold[0];
    int mini = v[0],miniInd = 0;

    vector<int> nse(n, -1);
    stack<int> st;

    for(int i = 0; i <n; i++) {
        while(!st.empty() && v[st.top()] >= v[i]) {
            st.pop();
        }
        if(!st.empty()) nse[i] = st.top();
        st.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        int less;
        less = i - nse[i]-1;
        if(nse[i]==-1) less = i;
        if(i+1<n&&v[i+1]<v[i]) ans = max(ans, hold[0] + less - 1);
        else ans = max(ans,hold[0] + less);
        
    }
    // cout<<hold[0]<<" ";
    cout<<ans<<endl;
    
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


