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

    sort(v.begin(),v.end());
    int i;
    int prev = n-1;
    int ans = 0;
    ans = 0;
    int rel = 0;
    for (i = 0; i < n; i++)
    {
        int idx = upper_bound(v.begin(),v.end(),v[i]) - v.begin();
        if(idx<n){

            int add = (n - idx);
            if(rel < add){ 
                ans = ans + (idx-i)*add - (idx-i)*rel;
                rel+= (idx-i);
            }
            i = idx - 1;
        }
    }

    if(ans==0) ans = n/2;
    

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
