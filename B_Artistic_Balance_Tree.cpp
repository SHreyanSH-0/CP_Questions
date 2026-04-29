#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n),v2(m);
    priority_queue<int> odd, even;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        ans += v[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>v2[i];
    }


    vector<int> hold(n);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i+=2)
    {
        if(v[i]>=0)
        odd.push(v[i]);
        maxi = max(maxi,v[i]);
    }
    
    if(odd.empty()){
        odd.push(maxi);
    }
    maxi = INT_MIN;
    
    for (int i = 1; i < n; i+=2)
    {
        if(v[i]>=0)
        even.push(v[i]);
        maxi = max(maxi,v[i]);
    }
    if(even.empty()){
        even.push(maxi);
    }
    
    for (int i = 0; i < m; i++)
    {
        if(v2[i]%2==1){
            if(odd.empty()) continue;
            else{
                ans -=odd.top();
                odd.pop();
            } 
        }
        else{
            if(even.empty()) continue;
            else{
                ans -= even.top();
                even.pop();
            } 
        }
    }
    
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
