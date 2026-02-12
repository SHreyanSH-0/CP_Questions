#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
bool check = false;
int rec(vector<vector<int>> &v, int node, int ret, vector<int>&vis,int ct, int a){
    if(node == ret){
        check = true;
        return 0;
 
    } 
    vis[node] = 1;
    int ans = 1;
    int c = false;
    for(auto &it : v[node]){
        if(vis[it]) continue;
        int hold = rec(v,it,ret,vis,ct+1,a);
        if(hold==0) c = true;
        else ans += hold;
    }
    if(c&&node!=a) return 0;
    return ans;
}
void solve()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<int> vis(n+1,0);
    check = false;
    vector<vector<int>> v(n+1);
    for(int i=0;i<m;i++){
        int a1,b1;
        cin>>a1>>b1;
        v[a1].push_back(b1);
        v[b1].push_back(a1);
    }
 
    int ct1 = rec(v,a,b,vis,0,a);
    int ct2 = rec(v,b,a,vis,0,b);
    // cout<<ct1<<" "<<ct2<<endl;
    if(!check) cout<<0<<endl;
    else
    cout<<(ct1-1)*(ct2-1)<<endl;
 
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
