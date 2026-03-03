#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int x;
    cin>>x;
    string s = to_string(x);
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sum += s[i] - '0';
    }
    if(s[0]!='1') s[0] = s[0] - 1;
    sort(s.rbegin(),s.rend());

    if(sum>9){
        int ans = 0;
       for (int i = 0; i < s.size()&&sum>9; i++)
       {
            sum -= s[i] - '0';
            ans++;
       }
       cout<<ans<<endl;
       
    }
    else cout<<0<<endl;
    
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
