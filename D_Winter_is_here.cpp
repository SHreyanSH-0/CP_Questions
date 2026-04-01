#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007 bbb   
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    vector<int> ct(1e6+1, 0);
    for(int i=0;i<n;i++){
        int hold = v[i];
        int l = sqrt(hold);
        for(int j = 1;j<=l;j++){
            if(hold%j==0) {
                ct[j]++;
                if(j!=hold/j)
                ct[hold/j]++;
            }
        }
    }

    int ans = 0;
    
    
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
