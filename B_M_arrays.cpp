#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> hold(m,0);
    for (int i = 0; i < n; i++)
    {
        hold[v[i]%m]++;
    }

    int ans = hold[0]>0?1:0;
    int last = m -1;
    for(int i=1;i<=last;i++,last--){
        if(hold[i]==0&&hold[last]==0){
            continue;
        }
        else{
            if(abs(hold[i]-hold[last])==0 ) ans++;
            else ans+=abs(hold[i]-hold[last]);
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
