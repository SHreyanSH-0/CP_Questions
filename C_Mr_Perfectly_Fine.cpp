#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(2));
    int ans = INT_MAX;
    int first = INT_MAX, second = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int a; 
        string s;
        cin>>a>>s;
        if(s=="10"){
            first = min(first,a);
        }
        else if(s=="11"){
            ans = min(ans,a);
        }
        else if(s=="01"){
            second = min(second,a);
        }
    }
    ans = min(ans,first + second);
    if(ans>=INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
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
