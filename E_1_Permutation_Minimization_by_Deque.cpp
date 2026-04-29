#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if(dq.empty()) dq.push_back(v[i]);
        else{
            if(dq[0]>=v[i]) dq.push_front(v[i]);
            else dq.push_back(v[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<dq[i]<<" ";
    }cout<<endl;
    
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
