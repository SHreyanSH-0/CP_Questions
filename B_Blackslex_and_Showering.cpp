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
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    int ans = 0;
    for(int i=0;i<n-1;i++){
        ans += abs(v[i] - v[i+1]);
    }
    int hold = ans;
    for(int i=0;i<n;i++){
        if(i==0){
            ans = min(ans, hold - abs(v[i] - v[i+1]));
        }
        else if(i==n-1){
            ans = min(ans, hold - abs(v[i] - v[i-1]));
        }
        else{
            ans = min(ans, hold - abs(v[i] - v[i-1]) - abs(v[i]-v[i+1]) + abs(v[i-1] - v[i+1]));
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
