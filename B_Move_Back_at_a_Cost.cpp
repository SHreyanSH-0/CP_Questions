#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        ms.insert(v[i]);
    }
    vector<int> ans;
    priority_queue<int, vector<int>,greater<int>> pq;
    for (int i=0;i<n-1;i++)
    {
        if(v[i]!=*ms.begin()){
            auto it = ms.find(v[i]);
            ms.erase(it);
            ms.insert(v[i]+1);
            pq.push(v[i] + 1);
        }
        else{
            ans.push_back(v[i]);
            ms.erase(ms.begin());
        }
    }

    if(!pq.empty()&&v[n-1]>pq.top()) pq.push(v[n-1]+1);
    else ans.push_back(v[n-1]);
    
    // for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";cout<<endl;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    
    
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";cout<<endl;
    
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
