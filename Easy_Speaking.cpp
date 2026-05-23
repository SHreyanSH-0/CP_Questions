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
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='u'||s[i]=='o'||s[i]=='i'||s[i]=='e'||s[i]=='a') ct = 0;
        else ct++;
        if(ct>=4){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
    
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
