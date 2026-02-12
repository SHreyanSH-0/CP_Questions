#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    if(n%2==1){
        cout<<1<<" "<<n/2<<" "<<n/2<<endl;
    }
    else{
        if((n/2)%2==1){
            cout<<2<<" "<<n/2 - 1<<" "<<n/2 - 1<<endl;
        }
        else{
            cout<<n/4<<" "<<n/4<<" "<<n/2<<endl;

        }
    }
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
