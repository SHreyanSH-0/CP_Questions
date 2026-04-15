#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
#pragma omp parallel
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }

    map<int,int> map1, map2;

    for (int i = 0; i < n; i++)
    {
        map2[a[i]]++;
        map2[b[i]]++;
    }
    
    
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
