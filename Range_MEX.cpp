#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    int z = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(v[i]==0) z++;
    }
    if(z==n&&k==0){
        cout<<2<<endl;
        return;
    }
    int ans = k+1;
    for(int i=0;i<n;i++){
        set<int> hold;
        while(i<n&&v[i]!=k){
            if(v[i]<k) hold.insert(v[i]);
            i++;
        }
        int h = hold.size();
        ans = min(ans,k+1-h);
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
