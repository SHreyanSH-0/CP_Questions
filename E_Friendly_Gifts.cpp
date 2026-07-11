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
    vector<vector<int>> hold(n+1);
    for (int i = 0; i < n; i++)
    {
        int maxi = v[i], mini = v[i];
        set<int> s;
        for (int j = i; j < n; j++)
        {
            s.insert(v[j]);
            maxi = max(v[j],maxi);
            mini = min(v[j],mini);
            if(maxi - mini + 1 == s.size() && s.size()==j - i + 1){
                hold[s.size()].push_back(mini);
            }
        }        
    }
    int ans = 0;
    for (int i = 1; i <= n/2; i++)
    {
        sort(hold[i].begin(),hold[i].end());
        for (int j = 0; j < hold[i].size(); j++)
        {
            int idx = lower_bound(hold[i].begin(),hold[i].end(),hold[i][j] + i) - hold[i].begin();
            if(idx<hold[i].size()&&hold[i][idx]==hold[i][j] + i){
                ans = i;
                break;
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
