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
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.rbegin(),v.rend());
    for (int i = 1; i < n; i++)
    {
        if(v[i]==v[i-1]) check = false;
    }
    
    if(check){
        for (int i = 0; i < n; i++)
        {
            cout<<v[i]<<" ";
        }
    }
    else {
        cout<<-1;
    }
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
