#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    vector<int> diff(n-1);
    int ans = k;
    for (int i = 1; i < n; i++)
    {
        diff[i-1] = v[i] - v[i-1];
        ans += diff[i-1];
    }   

    sort(diff.rbegin(),diff.rend());    
    for (int i = 0; i < k-1; i++)
    {
        ans -= diff[i];
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
