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
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(v[i]==1) one++;
    }
    
    sort(v.rbegin(),v.rend());
    int ans = 0;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if(v[i]>=2){
            ans+=v[i];
            int hold = v[i]/2 - 1;
            if(one <= hold){
                ans += one;
                one = 0;
            }
            else {
                ans += hold;
                one -= hold;
            }
            last = i;
        } 
    }    
    if(last==0&&one>0) ans++;
    if(ans < 3) ans = 0;
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
