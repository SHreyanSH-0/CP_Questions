#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> q(n),r(n);
    for (int i = 0; i < n; i++)
    {
        cin>>q[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>r[i];
    }

    sort(q.begin(),q.end());
    sort(r.begin(),r.end());
    int ans = 0;
    int rp = 0;
    for (int i = n-1; i>=0; i--)
    {   
        int y = r[rp]+1;
        int x = y * q[i] + r[rp];
        if(x>y&&y>=1&&x<=k){
            ans++;
            rp++;
        }
    }
    cout<<ans<<endl;
    
    
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
