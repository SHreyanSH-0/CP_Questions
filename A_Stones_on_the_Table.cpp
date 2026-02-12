#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        if(s[i]==s[i+1]) ans++;
    }
    cout<<ans;
}
int main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
