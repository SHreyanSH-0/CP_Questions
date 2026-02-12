#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    int ans = 0;
    int ind = 0;
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>=b[i] + prev){
            ind+= a[i] - b[i] - prev;
            prev = a[i];
        }
        else
        {
            prev = b[i] + prev;
        }
    }
    
    ind = min(ind,m);
    ans += ind * prev;

    int hold = m - ind;

    ans += (hold*(2*prev + hold + 1))/2;

    cout<<ans<<endl;


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
