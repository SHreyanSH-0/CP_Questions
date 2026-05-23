#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int z,o,t;
    z=o=t=0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(v[i]==0) z++;
        else if(v[i]==1) o++;
        else t++;
    }
    int hold = (min(t,o));

    o -= hold;
    t -= hold;

    o/=3;
    t/=3;

    cout<<hold + z + o + t<<endl;
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
