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
    int maxi = 0, mini= 0;
    for (int i = 1; i < n-1; i++)
    {
        if(s[i-1]=='1'&&s[i+1]=='1') s[i] = '1';
    }
    for (int i = 0; i < n; i++)
    {
        int ct = 0;
        while(i<n&&s[i]=='1') {
            ct++;
            i++;
        }
        maxi += ct;
        if(ct>2)
        mini += ct - (ct-1)/2;
        else mini += ct;
    }
    cout<<mini<<" "<<maxi<<endl;
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