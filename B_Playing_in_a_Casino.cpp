#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>> v(m,vector<long long>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>v[j][i];
        }
    }
    ll ans = 0;
    
    for (long long i = 0; i < m; i++)
    {
        ll s = 0;
        sort(v[i].begin(),v[i].end());
        for(long long j=0;j<n;j++){
            s+=v[i][j];
        }
        for(long long j=n-1;j>=0;j--){
            s-= v[i][j];
            ans += (j)*v[i][j] - s;
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
