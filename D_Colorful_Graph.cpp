#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    map<int,vector<int>> map;
    vector<int> colors(n+1);

    for (int i = 0; i < n; i++)
    {
        cin>>colors[i+1];
        map[colors[i+1]].push_back(i+1);
    }
    vector<vector<int>> v(n+1);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int div = 0, ans = 1e8;
    for(auto&[color,vec]:map){
        set<int> hold;
        for(int i=0;i<vec.size();i++){
            for(auto&it : v[vec[i]]){
                if(colors[it]!=color) hold.insert(colors[it]);
            }
        }
        if(hold.size()>div){
            ans = color;
            div = hold.size();
        }
        else if(hold.size()==div){
            ans = min(ans,color);
        }
    }
    
    cout<<ans<<endl;


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
