#include <bits/stdc++.h>
using namespace std;
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

    int ct = 0;
    int m = v[0];
    
    vector<int> pending;
    vector<pair<int,int>> edges;
    int k = 0;
    for(int i=1;i<n;i++){
        if(v[i]<m){
            pending.push_back(m);
            m = v[i];
        }
        else{
            edges.push_back({m,v[i]});
        }
        while(k<pending.size()){
            if(pending[k]<v[i]){
                edges.push_back({pending[k],v[i]});
                k++;
            }
            else{
                break;
            }
        }
    }

    if(k==pending.size()){
        cout<<"Yes"<<endl;
        for (int i = 0; i < edges.size(); i++)
        {
            cout<<edges[i].first<<" "<<edges[i].second<<endl;
        }
        
    }
    else
    cout<<"No"<<endl;
}
int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
