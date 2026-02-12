#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define int long long
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);

    for(auto &it : v) cin>>it;

    sort(v.begin(),v.end());
    
    long long ans = 0;

    for(int i=0;i<n;i++){
        int low = upper_bound(v.begin(),v.end(),v[i]+2) - v.begin() - 1;
        if(low-i>=2){
            int hold = low - i;
            ans += (hold*(hold-1))/2;
        }
    }
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
