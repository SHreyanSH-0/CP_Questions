#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> v(n+1);

    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> color(n+1,-1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        

        if(color[i]==-1){

            queue<pair<int,int>> q;
            q.push({i,0});
            bool check = true;
            int one =0, zero = 0;
            while(!q.empty()){
                auto it = q.front();
                q.pop();
                int node = it.first;
                int col = it.second;
                // cout<<node<<" "<<col<<" "<<color[i]<<endl;
                if(color[node]!=col&&color[node]!=-1){
                    check = false;
                    continue;
                }
                else if(color[node]==col) continue;
                if(col==0) zero++;
                else one++;
                color[node] = col;
                for(auto &it:v[node]){
                    if((!col)==color[it]) continue;
                    // cout<<node<<" "<<it<<" "<<col<<" "<<!col<<endl;
                    q.push({it,!col});
                }
            }
            if(check) ans += max(one,zero);
        }
        
    }
    cout<<ans<<endl;
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
