#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(int n, int m){
    if(n==m) return 0;
    if(n%3==0){
        return min(1+rec(n/3,m) , 1 + rec(2 * (n/3),m));
    }
    else {
        return 1e8;
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    if(rec(n,m)>=1e8) cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
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
