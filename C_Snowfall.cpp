#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    vector<int> six,two,three,rest;
    for (int i = 0; i < n; i++)
    {
        if(v[i]%6==0) six.push_back(v[i]);
        else if(v[i]%2==0){
two.push_back(v[i]);
        }
        else if(v[i]%3==0){
three.push_back(v[i]);
        }
        else{
rest.push_back(v[i]);
        }
    }
    
    for (int i = 0; i < six.size(); i++)
    {
        cout<<six[i]<<" ";
    }
    for (int i = 0; i < two.size(); i++)
    {
        cout<<two[i]<<" ";
    }
    for (int i = 0; i < rest.size(); i++)
    {
        cout<<rest[i]<<" ";
    }
    for (int i = 0; i < three.size(); i++)
    {
        cout<<three[i]<<" ";
    }
    

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
