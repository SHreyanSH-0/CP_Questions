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
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int ct = 1;
    bool check = false;
    for (int i = 0; i < n-1; i++)
    {
        if(v[i]>v[i+1]){
            check = true;
        }
    }

    if(check){
        cout<<1<<endl;
    }
    else{
        cout<<n<<endl;
    }
    
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
