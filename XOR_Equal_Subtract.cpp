#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
bool check(int a, int b){
    if(a<b){
        int hold = a;
        a = b;
        b = hold;
    }
    
    while(a>0&&b>0){
        if(a%2!=b%2) {
            if(b%2==1) return false;
        }
        a/=2;
        b/=2;
    }
    return true;
}

map<int,int> m;

int rec(vector<int>&v,int i, int bits){
    if(i>=v.size()) return 0;
    int hold = ((bits<<8)|i);
    if(m.find(hold)!=m.end()) return m[hold];
    int p = 0, np = 0;

    if(bits==0){
        p = 1 + rec(v,i+1,(bits|v[i]));
        np = rec(v,i+1,bits);
    }
    else{
        if(check(v[i],bits)){
            p = 1 + rec(v,i+1,v[i]);
            np = rec(v,i+1,bits);
        }
        else {
            np = rec(v,i+1,bits);
        }
    }
    return m[hold] = max(p,np);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    cout<<rec(v,0,0)<<endl; 
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
        m.clear();
    }
    return 0;
}
