#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,a,b;

    cin>>n>>a>>b;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;

        ans = min(ans,abs(a-x)+abs(b-y));
    }
    cout<<ans<<endl;
    
}
int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
