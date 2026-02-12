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
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string hold;
        for (int j = 0; j < 4&&j+i<n; j++)
        {
            hold.push_back(s[j+i]);
        }
        if(hold=="2025"){
            ans = 1;
        }   
        else if(hold=="2026"){
            ans =0;
            break;
        }     
    }

    cout<<ans<<endl;
    
    
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
