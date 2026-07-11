#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin>>v[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin>>v[i].second;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> hold;
        for (int j = 0; j < n; j++)
        {
            if(i==j) continue;
            if(v[j].first >= v[i].first) hold.push_back(0);
            else
            hold.push_back((v[i].first - v[j].first) * v[j].second);
        }

        sort(hold.begin(),hold.end());
        int cost = 0;
        for (int j = 0; j < k; j++)
        {
            cost += hold[j];
        }

        ans = max(ans, v[i].first * k - cost);
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
