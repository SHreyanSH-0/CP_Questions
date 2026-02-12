#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    int y = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='Y'){
            y++;
        }
    }
    if(y>1)
    cout<<"NO"<<endl;
    else 
    cout<<"YES"<<endl;
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
