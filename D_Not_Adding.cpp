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
    vector<bool> hold(1e6 + 1, false);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        hold[v[i]] = true;
    }

    sort(v.begin(),v.end());

    int ans = 0;

    for (int i = 1; i <= 1e6; i++)
    {
        if(hold[i]) continue;
        int x = 0;
        for(int j=2*i;j<=1e6;j+=i){
            if(hold[j]) x = __gcd(x,j/i);
        }
        if(x==1) ans++;
    }
    

    cout<<ans<<endl;    
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// ..cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
