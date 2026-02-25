#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> ans(n+1,0);
    vector<int> next(n+1,0);
    for(int i=0;i<=n;i++) next[i] = i+1;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int j = a;
        
        while(j<c){
            if(ans[j]==0) ans[j] = c;
            int hold = j;
            j = next[j];
            next[hold] = c;
        }
        
        while(j<=b){
            if(ans[j]==0&&j!=c) ans[j] = c;
            int hold = j;
            j = next[j];
            next[hold] = b+1;
        }
    }    
    for (int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
    
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
