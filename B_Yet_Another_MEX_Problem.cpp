#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int it = 0;
    int ct = 0;
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++)
    {
        if(v[i]==it&&ct<k-1) {
            it++;
            ct++;
        }
    }
    cout<<it<<endl;
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
