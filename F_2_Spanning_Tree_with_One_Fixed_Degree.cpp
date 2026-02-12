#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

class dsu{
    public:
    vector<int> par, size;
    dsu(int n){
        for(int i=0;i<=n;i++){
            par.push_back(i);
            size.push_back(1);
        }
    }

    int parent(int a){
        if(par[a]!=a) par[a] = parent(par[a]);
        return par[a]; 
    }

    void unite(int a, int b){
        int para = parent(a);
        int parb = parent(b);

        if(para == parb) return;

        if(size[para]>=size[parb]){
            par[parb] = para;
            size[para] += size[parb];
            size[parb] = 0;
        }
        else{
            par[para] = parb;
            size[parb] += size[a];
            size[para] = 0;
        }
    }

    void fun(int n){
        size[n] = 1e5;
    }
};

void rec(vector<vector<int>> &v, int node, vector<bool> &vis, dsu&d){
    if(vis[node]) return;
    vis[node] = true;
    for(auto &it : v[node]){
        if(it == 1) continue;
        if(!vis[it]){
            rec(v,it,vis,d);
        }
        d.unite(node,it);
    }
}

void solve()
{
    int n,m,d;
    cin>>n>>m>>d;
    vector<vector<int>> v(n+1);
    vector<pair<int,int>> ans;
    vector<bool> vis(n+1,false);
    dsu dd(n+1);
    vis[1] = true;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=0;i<v[1].size();i++){
        dd.fun(v[1][i]);
        rec(v,v[1][i],vis,dd);
    }   
    
    vector<int> vis2(n+1,false);
    int ct = 0;
    vis2[1] = true;
    queue<int> q;
    for(int i=0;i<v[1].size();i++){
        if(!vis2[dd.parent(v[1][i])]){
            vis2[dd.parent(v[1][i])] = true;
            q.push(dd.parent(v[1][i]));
            ans.push_back({1,dd.parent(v[1][i])});
            ct++;
        }
    }
    for(int i=0;i<100;i++){
        cout<<ans[i].first<<endl;
    }
    if(ct<d){
        for(int i=0;i<v[1].size();i++){
            if(!vis2[(v[1][i])]&&ct<d){
                vis2[(v[1][i])] = true;
                q.push((v[1][i]));
                ans.push_back({1,v[1][i]});
                ct++;
            }
        }
    }
    if(ct!=d) {
        cout<<"NO"<<endl;
        return;
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis2[node] = true;
        for(auto &it : v[node]){
            if(!vis2[it]){
                vis2[it] = true;
                ans.push_back({node,it});
                q.push(it);
            }
        }
    }
    
    if(1){
        cout<<"YES"<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }
    else{
        cout<<"NO"<<endl;
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
