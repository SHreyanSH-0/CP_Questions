#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m,h;
    cin>>n>>m>>h;
    vector<int> a(n),b(m),c(m);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>b[i]>>c[i];
        b[i]--;
    }
    int ind = -1;
    
    map<int,int> map;

    for (int i = 0; i < m; i++)
    {
        if(a[b[i]] + map[b[i]] + c[i]>h){
            ind = i;
            map.clear();
        }
        else{
            map[b[i]] += c[i];
        }

    }

    for (int i = ind+1; i < m; i++)
    {
        a[b[i]] = a[b[i]] + c[i];
        
    }

    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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
