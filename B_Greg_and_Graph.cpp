#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;

    cin>>n;
    vector<vector<int>> dist(n+1,vector<int>(n+1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>dist[i][j];
        }
    }

    vector<int> x(n);

    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
    }

    vector<int> vertex;
    vector<int> ans;
    reverse(x.begin(),x.end());

    for (int i = 0; i < n; i++)
    {
        vertex.push_back(x[i]);
        int sum = 0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){                
                dist[j][k] = min(dist[j][k], dist[j][x[i]] + dist[x[i]][k]);
            }
        }
        for(int j=0;j<vertex.size();j++){
            for(int k=0;k<vertex.size();k++){
                sum += dist[vertex[j]][vertex[k]];
            }
        }
        ans.push_back(sum);
        
    }
    

    reverse(ans.begin(),ans.end());

    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
    

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
