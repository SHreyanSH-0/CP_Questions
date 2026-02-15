#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n , k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> v(26,0);
    map<char,int> map;
    int ans = 0;
    int hold = 0;
    k++;
    for (int i = 1; i < k; i++)
    {
        if(s[i]!=s[i-1])hold++;
    } 
    int j = 0;
    ans = hold;
    for (int i = k; i < n; i++,j++)
    {
        if(s[j]!=s[j+1]) hold--;
        if(s[i]!=s[i-1]) hold++;
        ans += hold;
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
