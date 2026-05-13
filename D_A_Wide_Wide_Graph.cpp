#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(vector<vector<int>> &v, int node,int par, int dist, int &maxDist){
    int ans =-1;
    if(dist>=maxDist){
        maxDist = dist;
        ans = node;
    }
    for(auto&it : v[node]){
        if(it==par) continue;
        int hold = rec(v,it,node, dist+1,maxDist);
        if(hold!=-1) ans = hold;
    }
    return ans;
}
void rec2(vector<vector<int>> &v, int node,int par, int d, vector<int>&dist){
    dist[node] = d;
    for(auto&it : v[node]){
        if(it==par) continue;
        rec2(v,it,node, d+1,dist);
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int maxDist = 0;
    int dia1 = rec(v,1,-1, 0,maxDist);
    int dia2 = rec(v,dia1,-1, 0,maxDist);
    vector<int> dist1(n+1,0), dist2(n+1,0);
    rec2(v,dia1,-1, 0,dist1);
    rec2(v,dia2,-1, 0,dist2);
    for (int i = 1; i <= n; i++)
    {
        dist1[i] = max(dist1[i],dist2[i]);
    }
    
    sort(dist1.begin(),dist1.end());

    for (int i = 1; i <= n; i++)
    {
        int idx = lower_bound(dist1.begin(),dist1.end(),i) - dist1.begin();
        if(idx<=n){
            cout<<idx<<" ";
        }
        else cout<<n<<" ";
    }cout<<endl;
    
    
    
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
