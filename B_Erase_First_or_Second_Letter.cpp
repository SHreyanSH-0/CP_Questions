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
    unordered_map<char,int> map;

    for (int i = 0; i <n; i++)
    {
        map[s[i]]++;
        ans+=map.size();
    }
    cout<<ans<<endl;
        
}
int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
