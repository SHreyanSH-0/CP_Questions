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

    sort(v.begin(),v.end());
    int ans = 0;
    for(int k=0;k<n;k++){

        int x = -v[k];
        for (int i = 0; i < n; i++)
        {
            v[i] +=x;
        }
        
        int start = 0;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            if(v[i]>=0)
            s.insert(v[i]);
        }
        
        for (auto &it:s)
        {
            if(it==start) start++;
            else break;
        }
        ans = max(ans,start);
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
