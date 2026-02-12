#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007



void solve()
{
    int n;
    cin>>n;
    vector<int> a(n), c(n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        m = max(m,a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }

    cout<<rec(a,c,0,-1)<<endl;
    
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
