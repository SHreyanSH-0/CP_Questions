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

    vector<int> pos(n+1,0), neg(n+1,0);
    int ans1 = 0,ans2 = 0;
    for(int i=1;i<=n;i++){
        int idx = i-1;

        if(v[idx]>0){
            neg[i] = neg[i-1];
            pos[i] = 1 + pos[i-1];
        }
        else{
            neg[i] = pos[i-1] + 1;
            pos[i] =  neg[i-1];
        }
        ans1 += neg[i];
        ans2 += pos[i];
    }

    cout<<ans1<<" "<<ans2<<endl;

    
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
