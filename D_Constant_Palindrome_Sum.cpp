#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,limit;
    cin>>n>>limit;
    vector<int> v(n);
    vector<int> diff(2*limit + 2,0);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    for (int i = 0; i < n/2; i++)
    {
        int a = v[i];
        int b = v[n - i - 1];

        int minVal = min(a,b) + 1;
        int maxVal = max(a,b) + limit;

        diff[2] += 2;
        diff[2*limit + 1] -= 2;

        diff[minVal] += -1;
        diff[maxVal + 1] -= -1;

        diff[a+b] += -1;
        diff[a+b+1] -= -1;
    }

    int ans = INT_MAX;
    for(int i=2;i<=2*limit;i++){
        diff[i] += diff[i-1];
        ans = min(ans,diff[i]);
    }
    
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
