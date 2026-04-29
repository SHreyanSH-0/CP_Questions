#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    string ans(n,'A');
    string hold;
    char prev = 'A';
    for (int i = 0; i < n; i++)
    {
        if(s[i]>=prev){
            ans[i] = s[i];
            prev = s[i];
        }
        else hold.push_back(s[i]);
    }

    sort(hold.begin(),hold.end());
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if(ans[i]=='A') {
            ans[i] = hold[idx++]; 
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
