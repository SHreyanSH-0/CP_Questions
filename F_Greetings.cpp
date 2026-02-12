#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int a1,b1;
        cin>>a1;
        cin>>b1;
        v[i] = {a1,b1};
        a[i] = a1;
    }
    int ans = 0;
    sort(a.begin(),a.end());
    sort(v.begin(),v.end());
    map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        

        
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
