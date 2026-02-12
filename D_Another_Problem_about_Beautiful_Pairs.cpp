#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    int ans = 0;
    vector<int> p;
    for(auto &it : s) p.push_back(it);
    for (int i = 0; i < n; i++)
    {
        for(int j = 0;j<p.size();j++){
            int it = p[j];
            if(i + a[i]*it>=n) break;
            if(a[i + a[i]*it]==it) ans++;
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
