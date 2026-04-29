#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n+1);
    vector<vector<int>> edges(n,vector<int>(2));
    map<pair<int,int>,int> map;
    for(int i=0;i<n-1;i++){
        cin>>edges[i][0]>>edges[i][1];
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    int ct = 0;
    for(int i=0;i<v.size();i++){
        if(v[i].size()==1&&ct<n-1){
            map[{i,v[i][0]}] = ct;
            map[{v[i][0],i}] = ct;
            ct++;
        }
    }

    for(int i=0;i<n-1;i++){
        if(map.find({edges[i][0],edges[i][1]})!=map.end()){
            cout<<map[{edges[i][0],edges[i][1]}]<<endl;
        }
        else cout<<ct++<<endl;
    }

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
