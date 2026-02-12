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
    vector<int> v2(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        v2[i] = v[i];
    }
    
    int low = v[0] + 2*v[1], high = 0;
    for (int i = 2; i < n; i++)
    {
        low = low + 2*v[i];
    }
    high = 2*v[n-1] + v[n-2];
    for (int i = n-3; i>=0; i--)
    {
        high = 2*high + v[i];
    }
    cout<<low <<" "<<high<<endl;
    
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
