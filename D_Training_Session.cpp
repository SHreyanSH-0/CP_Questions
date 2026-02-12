#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n+1);
    map<int,int> map;
    for (int i = 0; i < n; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        map[b]++;
    }
    int ans = (n*(n-1)*(n-2))/6;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i].size()>=2){
            for (int j = 0; j < v[i].size(); j++)
            {
                if(map.find(v[i][j])!=map.end())
                ans -= (map[v[i][j]] - 1)*(v[i].size()-1);
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