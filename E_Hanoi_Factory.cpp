#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

bool comp(vector<int>&a, vector<int>&b){
    if(a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}
void solve()
{
    int n;
    cin>>n;

    vector<vector<int>> v(n,vector<int>(3));

    for (int i = 0; i < n; i++)
    {   
        int a,b,h;
        cin>>a>>b>>h;
        v[i] = {a,b,h};
    }

    sort(v.begin(),v.end(),comp);
    
    // for(auto x : v){
    //     cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    // }
    
    int ans = 0;
    int sum = 0;
    vector<int> prev;
    stack<vector<int>> st;
    for (int i = n-1; i>=0; i--)
    {
        if(st.empty()||st.top()[0]< v[i][1]){
            sum += v[i][2];
            st.push(v[i]);
        }
        else{
            while(!st.empty() && st.top()[0] >= v[i][1]){
                sum -= st.top()[2];
                st.pop();
            }
            sum += v[i][2];
            st.push(v[i]);
        }
        ans = max(ans,sum);
    }    
    cout<<ans<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
