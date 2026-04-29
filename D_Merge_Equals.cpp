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
    map<int,set<int>> map;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        map[v[i]].insert(i);
    }

    multiset<pair<int,int>> ms;
    for(auto&[x,y]:map){
        ms.insert({x,y.size()});
    }
    while(!ms.empty()){
        auto it1 = ms.begin();
        auto it = *(it1);
        ms.erase(it1);
        if(it.second<=1) continue;
        
        set<int> &s = map[it.first];
        
        auto idx = s.begin();
        auto idx2 = idx;
        idx2++;
        int hold = v[*idx];
        v[*idx] = -1;
        v[*idx2] = 2*hold;
        
        auto it2 = ms.find({v[*idx2],map[v[*idx2]].size()});
        if(it2 != ms.end()) ms.erase(it2);
        
        int hold2 = *idx2;
        map[v[hold2]].insert(hold2);
        s.erase(idx);
        s.erase(idx2);
        ms.insert({v[hold2],map[v[hold2]].size()});
        ms.insert({hold,map[hold].size()});
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(v[i]!=-1) {
            ans++;
        }
    }cout<<ans<<endl;
    for(int i=0;i<n;i++){
        if(v[i]!=-1) {
            cout<<v[i]<<" ";
        }
    }
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
