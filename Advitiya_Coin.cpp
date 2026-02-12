#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n),ng1(n),ng2(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int ans = 0;
    int mini = v[0], maxi = v[0];
    for(int i=0;i<n;i++){
        mini = min(v[i],mini);
        maxi = max(v[i],maxi);
        if(maxi-mini>k&&mini!=1e12&&maxi!=-1e12){
            ans++;
            mini = 1e8;
            maxi = -1e8;
        }
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
