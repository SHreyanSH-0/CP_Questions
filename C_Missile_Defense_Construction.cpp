#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int x,m;
    cin>>x>>m;
    int hold = 1;
    int height = 0;
    int ct = 0;
    int ans = 0;
    while(hold+height<x&&ct<=m){
        height = height + hold;
        hold = height;
        ct++;
    }

    if(ct>=m) cout<<0<<endl;
    else{
        ct++;
        int diff = m - height;
        hold = m;
        ans ++;

        int left = m - ct;
        ans += left;
        cout<<ans<<endl;
    }
    
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
