#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int g = 0;
    sort(a.begin(),a.end());
    for(int i = 1;i<n;i++){
        g = __gcd(g,a[i] - a[i-1]);
    }
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    vector<int> ans(m,0);
    for (int i = 0; i < m; i++)
    {
        cout<<__gcd(a[0] + b[i] , g)<<" ";
    }
    
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
