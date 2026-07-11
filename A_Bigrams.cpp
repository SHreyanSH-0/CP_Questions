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

    for (int i = 0; i < n; i++)
    {
        if(v[i]>=3) {
            cout<<"YES"<<endl;
            return;
        }
        for(int j=i+1;j<n;j++){
            if(v[i]>=2 && v[j]>=2){
                cout<<"YES"<<endl;
                return;
            }
        }
    }

    cout<<"NO"<<endl;
    
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
