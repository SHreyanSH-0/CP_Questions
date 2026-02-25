#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i+=2){
        set<int> comp, comp2;
        for(int j = i;j<=n;j*=2){
            comp.insert(j);
            comp2.insert(v[j]);
        }
        if(comp != comp2){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    
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
