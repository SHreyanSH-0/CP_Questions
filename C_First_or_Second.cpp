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
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        sum -= v[i];
    }
    int m = 0;
    int s = v[0];
    sum += v[0];
    int ans = sum;
    for (int i = 1; i < n; i++)
    {
        sum += v[i];
        ans = max(ans,sum + s);
        s+= abs(v[i]);
    }
    cout<<ans<<endl;   
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
