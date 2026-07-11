#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int a,b,x;
    cin>>a>>b>>x;

    vector<pair<int,int>> a1,b1;
    int ct = 0;
    while(a>0){
        a1.push_back({a,ct});
        a/=x;
        ct++;
    }
    a1.push_back({a,ct});

    ct = 0;
    
    while(b>0){
        b1.push_back({b,ct});
        b/=x;
        ct++;
    }
    b1.push_back({b,ct});
    int ans = 1e15;
    for (int i = 0; i < a1.size(); i++)
    {
        for (int j = 0; j < b1.size(); j++)
        {
            ans = min(ans,a1[i].second + b1[j].second + abs(a1[i].first - b1[j].first));
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
