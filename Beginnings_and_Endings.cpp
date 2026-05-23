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
    int ans = 1e8;
    for(int i=0;i<n;i++){
        for (int j = i+1; j < n; j++)
        {
            if(v[i]==v[j]){
                int l = j - i + 1;
                ans = min(ans , n - l);
            }
        }
        
    }

    if(ans==1e8) cout<<-1<<endl;
    else cout<<ans<<endl;
    
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
