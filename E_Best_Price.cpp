#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n), b(n);
    set<int> s;
    int ans = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
    } 
    for(int i=0;i<n;i++){
        cin>>b[i];
        s.insert(b[i]);
    } 

    sort(b.begin(),b.end());
    sort(a.begin(),a.end());

    for(auto &it : s){
        int idx1 = lower_bound(b.begin(),b.end(),it) - b.begin();
        int idx2 = lower_bound(a.begin(),a.end(),it) - a.begin();
        int b = n - idx1;
        int neg = idx2 - (n - b);
        if(idx2 > n) idx2 = n;
        if(idx2<=n&&idx1<n){
            if(neg<=k){
                ans = max(ans, b * it);
            }
        }

    }

    
    cout<<ans<<endl;
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
