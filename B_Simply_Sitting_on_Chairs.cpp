#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
    }
    int hold = -1;
    for(int i=0;i<n;i++){
        if(p[i]<=i+1){
            hold = i;
        }
    }
    int l = n;
    int ans = 0;
    for(int i=0;i<l;i++){
        if(p[i]>hold){
            ans++;
            l = p[i]-1;
        }
        else if(p[i]<=i+1) ans++;
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
