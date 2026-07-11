#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1'&&(i+k<n)){
            s[i] = '0';
            if(s[i+k]=='1') s[i+k] = '0';
            else s[i+k] = '1';
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1') {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    
    

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
