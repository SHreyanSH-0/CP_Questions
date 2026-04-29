#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 676767677
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int ans = 0;
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];;
    }

    int idx = -1;

    for (int i = 0; i < n; i++)
    {
        if(v[i]==1) idx = i;
        else ans += v[i];
    }

    if(idx==n-1){
        cout<<ans+1<<endl;
    }
    else cout<<ans<<endl;
    
    
    
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
