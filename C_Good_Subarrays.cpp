#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = s[i] - '0';
    }

    vector<int> p(n);
    p[0] = v[0];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i-1] + v[i];
    }
    map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        if(i==0){
            map[1]++;
            ans += map[p[i] - i];
        }
        else{
            map[p[i-1] - (i - 1)]++;
            ans += map[p[i] - i];
        }
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
