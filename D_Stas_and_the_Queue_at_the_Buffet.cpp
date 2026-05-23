#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);

    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }

    //(n(bi) - ai) + j(ai + bi)
    vector<pair<int,int>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({a[i] - b[i],n*b[i] - a[i]});
    }
    int ans = 0;
    sort(vp.rbegin(),vp.rend());
    for(int i=0;i<n;i++){
        ans += (i+1)*(vp[i].first) + vp[i].second;
    }

    cout<<ans<<endl;
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
