#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    

    int mini = 0;
    int maxi = 0;

    for(int i=0;i<n;i++){
        int hold1 = mini;
        int hold2 = maxi;

        mini = min(hold1 - a[i], b[i] - hold2);
        maxi = max(hold2 - a[i], b[i] - hold1);
    }

    cout<<maxi<<endl;
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
