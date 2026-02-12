#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int z = 0;
    int o = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(v[i]==0) z++;
        else o++;
    }
    int start = -1 , end=-1;
    for (int i = 0; i < n; i++)
    {
        if(v[i]==0&&start==-1)  start = i;
        else if(v[i]==0) end = i;
    }
    if(end-start+1!=n) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
        
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
