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
    vector<vector<int>> graph(n+1);
    vector<int> ans(n,1e8);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if(i + v[i]<n){
            graph[i + v[i]].push_back(i);
            if(v[i]%2!=v[i + v[i]]%2){
                ans[i] = 1;
                q.push(i);
            }
            else{
                
            }
            
        }
        else{
            // q.push(i);
        }
        
        if(i - v[i]>=0){
            graph[i - v[i]].push_back(i);
            if(v[i]%2!=v[i - v[i]]%2){
                ans[i] = 1;
                q.push(i);
            }
            else{
                
            }
        }
        else{
            // q.push(i);
        }
    }
    vector<bool> vis(n,false);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(vis[node]) continue;
        vis[node] = true;

        for(auto&it : graph[node]){
            if(v[node]%2==v[it]%2){
                ans[it] = min(ans[it],1 + ans[node]);
                q.push(it);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(ans[i]==1e8) cout<<-1<<" ";
        else
        cout<<ans[i]<<" ";
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
