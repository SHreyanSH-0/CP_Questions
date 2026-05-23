#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,x,k;
    cin>>n>>x>>k;

    map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        map[a]++;
    }
    int ans = 0;
    vector<pair<int,int>> v;
    for(auto&[x,y]:map){
        v.push_back({x,y});
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<k&&i<v.size();i++){
        if(v[i].second + ans <= x){
            ans += v[i].second;
        }
        else{
            ans = x;
            break;
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
