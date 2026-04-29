#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,d;
    cin>>n>>d;
    vector<int> v(n);
    vector<int> dist(n,1e8);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(v[i]==0) dist[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if(v[i]==0){
            int j = (i + d)%n;
            int ct = 1;
            while(j!=i &&dist[j]>ct){
                dist[j] = ct;
                ct++;
                j = (j+d)%n;
            }
        }
    }
    // for(int i=0;i<n;i++) cout<<dist[i]<<" ";cout<<endl;
    int ans = *max_element(dist.begin(),dist.end());
    if(ans==1e8) ans = -1;
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
