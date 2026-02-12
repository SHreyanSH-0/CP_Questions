#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    unordered_set<int> s;
    vector<int> ans;
    int ct = 0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.insert(a);
    }
    queue<pair<int,int>> q;
    for(auto&it:s) q.push({1,it});
    while(ans.size()<m){
        int node = q.front().second;
        int curr = q.front().first;
        q.pop();
        
        if(!s.count(node+curr)&&ans.size()<m){
            ans.push_back(node+curr);
            s.insert(node + curr);
            ct += curr;
        } 
        if(!s.count(node-curr)&&ans.size()<m) {
            ans.push_back(node-curr);
            ct += curr;
            s.insert(node - curr);
        } 
        q.push({curr+1,node});
    }

    cout<<ct<<endl;
    for(auto &it : ans) cout<<it<<" ";
    cout<<endl;
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
