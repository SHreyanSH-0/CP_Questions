#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool check(int l,int b,int h,vector<int> &v){
    if(v[v.size()-1]>l||v[v.size()-1]>b||v[v.size()-1]>h) return false;
    if(h<max(l,b)){
        if(l>b){
            int hold = h;
            h = l;
            l = hold;
        }
        else{
            int hold = h;
            h = b;
            b = hold;
        }
    }
    if(v[v.size()-1]+v[v.size()-2]<=h &&min (l,b)>=v[v.size()-1]) return true;
    return false;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);

    v[0] = 1, v[1] = 2;

    for (int i = 2; i < n; i++)
    {
        v[i] = v[i-1] + v[i-2];
    }

    for (int i = 0; i < m; i++)
    {
        int b,l,h;
        cin>>b>>l>>h;
        if(check(l,b,h,v)) cout<<1;
        else cout<<0;
    }cout<<endl;
    
    
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
