#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,p;
    cin>>n>>p;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        sum += v[i];
    }

    if(sum<p) {
        cout<<-1<<endl;
        return;
    }

    sort(v.rbegin(),v.rend());

    int low = 1, high = n;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        int curr = 0;
        int minu = 0;
        for (int i = 0; i < n; i+=mid,minu++)
        {
            for (int j = 0; j < mid&&i+j<n; j++)
            {
                curr += max(0LL,v[i+j] - minu);
            }
        }
        if(curr>=p){
            ans = min(ans,mid);
            high = mid-1;
        }
        else low = mid + 1;
        
    }
    cout<<ans<<endl;
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
