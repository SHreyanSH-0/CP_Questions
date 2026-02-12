#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int w,d;
    cin>>w>>d;
    int ans = 0;
    int pow = 1;
    int a = w, b = d;
    for (int i = 0; i < 32; i++)
    {
        if(i%2==0){
            a -= pow;
            if(a<0) break;
        }
        else{
            b -= pow;
            if(b<0) break;
        }
        ans++;
        pow*=2;
    }
    a = w, b = d;
    int hold = 0;
    pow = 1;
    for (int i = 0; i < 32; i++)
    {
        if(i%2==1){
            a -= pow;
            if(a<0) break;
        }
        else{
            b -= pow;
            if(b<0) break;
        }
        if(a<0||b<0) break;
        hold++;
        pow*=2;
    }

    cout<<max(ans,hold)<<endl;
    
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
