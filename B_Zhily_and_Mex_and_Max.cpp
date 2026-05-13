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
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        s.insert(i);
    }

    int val = *max_element(v.begin(),v.end());

    int ans = 0;

    sort(v.begin(),v.end());
    
    int m = 0;

    for (int i = 0; i < n; i++)
    {
        if(v[i]==m) m++;
    }
    vector<int> hold;
    hold.push_back(val);
    if(m-1==val) m--;
    for (int i = 0; i < m; i++)
    {
        hold.push_back(i);
    }
    for (int i = m+1; i < n; i++)
    {
        hold.push_back(-1);
    }
    
    m = 0; 
    for (int i = 0; i < n; i++)
    {
        if(!s.empty()) s.erase(hold[i]);

        if(s.empty()) m = n;
        else m = *(s.begin());
        ans += (hold[0] + m);
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
