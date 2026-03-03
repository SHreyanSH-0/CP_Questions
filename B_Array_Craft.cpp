#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    int sum = 0;
    vector<int> ans(n+1);
    for (int i = y-1; i>=1; i--)
    {
        if(i%2==(y-1)%2){
            ans[i] = -1;
        }
        else ans[i] = 1;
    }
    for (int i = y; i <=x; i++)
    {
        ans [i] = 1;
    }
    for (int i = x+1; i <= n; i++)
    {
        if(i%2==(x+1)%2) ans[i] = -1;
        else ans[i] = 1;
    }    
    for (int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    cout<<endl;
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
