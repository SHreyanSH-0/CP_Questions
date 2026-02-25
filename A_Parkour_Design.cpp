#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int x,y;
    cin>>x>>y;
    if(y>0){
        int holdx = 2*y;
        if(x-holdx>=0&&(x-holdx)%3==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if(y==0){
        int holdx = 2*y;
        if(x-holdx>=0&&(x-holdx)%3==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else{
        int holdx = 4*abs(y);
        if(x-holdx>=0&&(x-holdx)%3==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
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
