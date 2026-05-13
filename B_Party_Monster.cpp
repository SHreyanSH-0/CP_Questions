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
    int open=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='(') open++;
        else open--;
    }

    if(open==0) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
    
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
