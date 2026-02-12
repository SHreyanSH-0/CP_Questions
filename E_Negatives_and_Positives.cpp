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
    int ans = 0;
    int mini = LLONG_MAX;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];

        ans+=abs(v[i]);

        if(v[i]<0) m++;

        mini = min(abs(v[i]),mini);
    }

    if(m%2==0) cout<<ans<<endl;
    else cout<<ans - 2*abs(mini)<<endl;
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
