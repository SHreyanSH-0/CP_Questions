#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int ct = 0;
    bool wear = false;
    for (int i = 0; i < n; i++)
    {
        if(v[i]<a&&!wear){
            ct++;
            wear = true;
        }
        else if(v[i]>b&&wear) {
            wear = false;
        }
        
    }
    cout<<ct<<endl;
    
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
