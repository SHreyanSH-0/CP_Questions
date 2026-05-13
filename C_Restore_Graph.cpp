#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    map<int,vector<int>> indices;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    for (int i = 0; i < n; i++)
    {
        indices[v[i]].push_back(i);
    }
    k--;
    vector<pair<int,int>> edges;
    for(auto&[d,curr]:indices){
        if(d==0) continue;

        if(indices.find(d-1)==indices.end()) {
            cout<<-1<<endl;
            return;
        }

        vector<int> prev = indices[d-1];

        int prevVert = prev.size();
        int currVert = curr.size();
        if(d==1){
            k++;
            if(prevVert*k < currVert) {
                cout<<-1<<endl;
                return;
            }
            int idx = 0;
            for (int i = 0; i < prev.size() && idx < curr.size(); i++)
            {
                for(int j = 0;j<k&&idx<curr.size();j++){
                    edges.push_back({prev[i],curr[idx++]});
                }
            }
            k--;
        }
        else{
            if(prevVert*k < currVert) {
                cout<<-1<<endl;
                return;
            }
            int idx = 0;
            for (int i = 0; i < prev.size() && idx < curr.size(); i++)
            {
                for(int j = 0;j<k&&idx<curr.size();j++){
                    edges.push_back({prev[i],curr[idx++]});
                }
            }
        }
        
    }

    if((int)edges.size()!=n-1){
        cout<<-1<<endl;
    }
    else{
        cout<<edges.size()<<endl;
        for (int i = 0; i < n-1; i++)
        {
            cout<<edges[i].first + 1<<" "<<edges[i].second + 1<<endl;
        }
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
