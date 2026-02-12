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
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        s += v[i];
    }
    if(s<0) cout<<ceil((double)abs(s)/n)<<endl;
    else cout<<0<<endl;
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
