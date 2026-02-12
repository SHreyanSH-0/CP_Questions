#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;

    vector<vector<int>> v(n+1);
    vector<int> deg(n+1,0);
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    int ans = n;
    
    queue<pair<int,int>> q;

    for (int i = 1; i < n+1; i++)
    {
        if(deg[i]==1||deg[i]==0){
            q.push({i,0});
        }
    }
    

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int node = it.first;
        int khold = it.second;

        if(khold>=k) continue;

        ans--;
        deg[node]--;

        for (int i = 0; i < v[node].size(); i++)
        {
            deg[v[node][i]]--;
            if(deg[v[node][i]]==1||deg[v[node][i]==0]){
                q.push({v[node][i],khold+1});
            }
        }
        
    }
    
    

    cout<<ans<<endl;
    


    
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
