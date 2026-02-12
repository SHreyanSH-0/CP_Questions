#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;cin>>n;
    int ans = 0;
    
    for(int i=0;i<=n/2;i++){
        if((n - 2*(i))%4 == 0){
            ans++;
        }
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
