#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> v(n+1);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i+1];
    }
    int mina=INT_MAX, minb=INT_MAX, minc=INT_MAX;
    int ind = 0;

    for (int i = x+1; i <= y; i++)
    {
        if(minb>v[i]){
            minb = v[i];
            ind = i;
        }
    }
    vector<int> hold;
    if(ind!=0){
        for (int i = ind; i <= y; i++)
        {
            hold.push_back(v[i]);
        }
        for (int i = x+1; i < ind; i++)
        {
            hold.push_back(v[i]);
        }
    }
    vector<int> l, r;
    for (int i = 1; i <= x; i++)
    {
        l.push_back(v[i]);
    }
    for (int i = y+1; i <= n; i++)
    {
        l.push_back(v[i]);
    }
    
    int i = 0 , j = 0;
    while(i<l.size()&&j<hold.size()){
        if(l[i]<hold[j]){
            cout<<l[i]<<" ";
            i++;
        }
        else{
            break;
        }
    }

    while(i<l.size()&&j<hold.size()){
        if(l[i]<hold[j]){
            cout<<l[i]<<" ";
            i++;
        }
        else{
            break;
        }
    }

    while(j<hold.size()) cout<<hold[j++]<<" ";
    while(i<l.size()) cout<<l[i++]<<" ";
    cout<<endl;
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
