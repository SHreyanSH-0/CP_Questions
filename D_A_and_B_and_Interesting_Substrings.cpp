#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    vector<int> a(26);
    for (int i = 0; i < 26; i++)
    {
        cin>>a[i];
    }

    string s;
    cin>>s;
    int n = s.size();
    vector<int> pref(n,0);
    pref[0] = a[s[0] - 'a'];
    vector<map<int,int>> map(26);
    
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i-1] + a[s[i] - 'a'];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<pref[i]<<" ";
    // }
    // cout<<endl;
    

    map[s[0]-'a'][0]++;

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if(map[s[i]-'a'].find(pref[i] - 2*a[s[i]-'a'])!=map[s[i]-'a'].end()){
            ans += map[s[i]-'a'][pref[i] - 2*a[s[i]-'a']];
        }
        map[s[i]-'a'][pref[i-1]]++;
    }
    cout<<ans<<endl;
    
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
