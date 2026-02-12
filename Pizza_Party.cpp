#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int b,g;
    cin>>b>>g;
    b = b+1;
    int ans = ceil((float)(b*4+g*3)/8);
    cout<<ans<<endl;
}
int main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
