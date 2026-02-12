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
    vector<int> v(26,0);
    for(int i=0;i<n;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            v[s[i]-'A']++;
        }
        else v[s[i]-'a']++;
    }

    sort(v.begin(),v.end());
    int ans = 0;
    ans = v[v.size()-1] +  v[v.size()-2];
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
