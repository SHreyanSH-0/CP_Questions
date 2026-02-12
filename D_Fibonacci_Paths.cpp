#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
map<pair<int,int>,int> m;
int rec(vector<int> &v,int prev,int i,int ct){
    if(i>=v.size()) return ct>=1;

    if(prev==-1){
        int p = rec(v,i,i+1,ct+1);
        int np = rec(v,prev,i+1,ct);
        return p + np;
    }
    else{
        int ind = lower_bound(v.begin(),v.end(),v[prev] + v[i]) - v.begin();
        if(ind<v.size()){
            int p = 0;
            if( m.find({prev,ind})!=m.end()){
                int p = rec(v,i,ind,ct+1);
            }
            int np = rec(v,prev,i+1,ct);

            return p + np;
        }
        else{
            int np = rec(v,prev,i+1,ct);
            return np;
        }
    }

}

void solve()
{
    int n,m1;
    cin>>n>>m1;
    vector<int> v(n);
    vector<vector<int>> edges;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    for (int i = 0; i < m1; i++)
    {
        long long e1,e2;
        cin>>e1>>e2;
        m[{e1,e2}]++;
        edges.push_back({e1,e2});
    }
    sort(v.begin(),v.end());
    cout<<rec(v,-1,0,0)<<endl;
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
