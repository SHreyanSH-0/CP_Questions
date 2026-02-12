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
    int ans = 0, m = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    ans = v[n-1];
    int next = ans - 1;
    for (int i = n-2; i >=0; i--)
    {
        if(v[i]>=next){
            ans += next;
            next--;
        }
        else{
            ans += v[i];
            next = v[i] - 1;
        }
        if(next<=0) break;
    }    
    cout<<ans<<endl;
}
signed main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}