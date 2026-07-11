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
    // vector<int> diff(n);
    for (int i = n-1; i>=0; i--)
    {
        if(a[i] > b[i] && i - 1 >=0){
            int diff= a[i] - b[i];

            a[i] = b[i];
            a[i-1]+= diff;
        }
        // diff[i] = a[i] - b[i];
    }

    for (int i = 0; i < n; i++)
    {
        if(a[i] < b[i]) a[i] = b[i];
    }

    if(a==b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    
    
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
