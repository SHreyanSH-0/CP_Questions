#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    string s1,s2;
    cin>>n>>k>>s1>>s2;
    
    int a = 0, b = 0 , c= 0;
    int z = 0, o = 0;
    for (int i = 0; i < n; i++)
    {
        if(s1[i]=='1') o++;
        else z++;
    }
    a = z*o;
    z = 0;
    o = 0;
    for (int i = 0; i < n; i++)
    {
        if(s2[i]=='1') o++;
        else z++;
    }
    b = z*o;
    z = 0;
    o = 0;
    for (int i = 0; i < n; i++)
    {
        if(s1[i]==s2[i]) z++;
        else o++;
    }
    c = z*o;
    n = (1<<k) + 1;
    int hold = ceil(n/3.0);
    int ans = (hold)*a + (hold)*b + (n - 2*hold)*c;
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
