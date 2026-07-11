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
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int ans = 0;
    if(n%2==1){
        for (int i = 1; i < n-1; i+=2)
        {
            if(max(v[i+1],v[i-1]) >= v[i]) ans += max(v[i+1],v[i-1]) - v[i] + 1;
        }
    }
    else{
        int hold1 = 0, hold2 = 0;
        vector<int> hold(n);
        for (int i = n-2; i>0; i-=2)
        {
            if(max(v[i+1],v[i-1]) >= v[i]) hold2 += max(v[i+1],v[i-1]) - v[i] + 1;
            hold[i] = hold2;
        }
        ans = hold2;
        for (int i = 1; i < n-1; i+=2)
        {
            if(max(v[i+1],v[i-1]) >= v[i]) hold1 += max(v[i+1],v[i-1]) - v[i] + 1;
            if(i + 3 < n-1)
            ans = min(ans, hold1 + hold[i+3]);
        }
        ans = min(ans,hold1);
    }
    cout<<ans<<endl;
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
