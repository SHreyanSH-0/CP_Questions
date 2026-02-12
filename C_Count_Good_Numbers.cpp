#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007

int fun(int n, vector<int> &v){
    if(n==0) return 0;
    int hold = n;
    for(int i=0;i<4;i++){
        hold -= n/v[i];
        
    }
    for(int i=4;i<10;i++){
        hold += n/v[i];
    }
    
    for(int i=10;i<v.size()-1;i++){
        hold -= n/v[i];
    }

    hold += n/210;

    return hold-1;
}

void solve()
{
    int r , l;
    cin>>l>>r;
    
    vector<int> v = {2,3,5,7,6,10,14,15,21,35,30,42,70,105,210};
    
    int a = fun(r,v);
    int b = fun(l-1,v);
    cout<<a- b<<endl;
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