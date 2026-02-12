#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
bool check = true;
void rec(vector<vector<int>> &v, int node, int grp, vector<int> &vis){
    if(vis[node]>0){
        if(grp!=vis[node]) check = false;
        return;
    }
    vis[node] = grp;
    for(auto &it: v[node]){
        int newgrp = (grp==1)? 2 : 1;
        rec(v,it,newgrp,vis);
    }
}

void solve()
{
    int m, n;
    cin>>n>>m;
    vector<vector<int>> v(n+1);
    vector<int> vis(n+1,0);
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }    

    for (int i = 1; i <= n; i++)
    {
        if(vis[i]==0) rec(v,i,1,vis);
    }

    if(!check) cout<<-1<<endl;
    else{
        vector<int> s1,s2;
        for (int i = 1; i <= n; i++)
        {
            if(vis[i]==1){
                s1.push_back(i);
            }
            else if(vis[i]==2){
                s2.push_back(i);
            }
        }
        cout<<s1.size()<<endl;
        for(auto &it:s1) cout<<it<<" ";
        cout<<endl;
        cout<<s2.size()<<endl;
        for(auto &it:s2) cout<<it<<" ";
        cout<<endl;
        
    }
    
}
signed main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
