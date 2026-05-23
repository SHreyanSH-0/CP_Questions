#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    vector<int> ans(n,0);
    ans[0] = 1;
    ans[1] = 1;
    int curr = m - 1;
    for(int i=2;i<n;i+=3){
        if(i + 2 >= n){
            cout<<-1<<endl;
            return;
        }
        ans[i] = 0;
        ans[i+1] = curr;
        ans[i+2] = curr;
        if(curr==1) curr = m - 1;
        else curr = 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
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
