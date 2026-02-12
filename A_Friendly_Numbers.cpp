#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int x;
    cin>>x;
    int ans = 0;
    for(int i=-1000;i<1000;i++){
        int hold = x + i;
        int a = hold;
        int sum = 0;
        while(a>0){
            sum += a%10;
            a/=10;
        }
        if(hold - sum == x) ans++;
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
