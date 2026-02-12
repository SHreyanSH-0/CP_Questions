#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int m = a[0];
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += max(a[i],a[(i+1)%n]);   
        m = max(a[i],m);
    }    
    cout<<ans - m<<endl;
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
