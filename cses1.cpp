#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    
    vector<ll> v(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        sum+=v[i];
    }

    sort(v.begin(),v.end());
    int start = 0;

    ll ans  = max(sum,2*v[n-1]);
    cout<<ans<<endl;
            
}
int main() {

    ll test=1;
// cin>>test;
    ll a = 12 * 1e14;
    cout<<a%mod;
    return 0;
    while(test--)
    {
        solve();
    }
    return 0;
}
