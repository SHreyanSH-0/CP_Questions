#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n+1);
    for (int i = 0; i < n; i++)
    {
        int hold;
        cin>>hold;
        v[hold].push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if(v[i].size() == 0){
            cout<<0<<" ";
            continue;
        }
        int ans = 1;
        int prev = 0;
        for(int j=1;j<v[i].size();j++){
            if((v[i][j] - v[i][prev] - 1) % 2 == 0){
                ans++;
                prev = j;
            }
        }
        cout<<ans<<" ";
    }cout<<endl;
    
    
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
