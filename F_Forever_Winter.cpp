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
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    map<int,int> map;
    for (int i = 1; i < n+1; i++)
    {
        // cout<<v[i].size()<<" ";
        map[v[i].size()]++;
    }
    int ans1 = -1, ans2 = -1;

    if(map.size()==2){
        for(auto &[x,y] : map){
            if(x!=1){
                ans1= x;
                ans2 = x - 1;
            }
        }

    }
    else{        
        for(auto &[x,y] : map){
            if(x!=1){
                if(y==1) ans1 = x;
                else ans2 = x - 1; 
            }
        }
    }

    cout<<ans1<<" "<<ans2<<endl;
    
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
