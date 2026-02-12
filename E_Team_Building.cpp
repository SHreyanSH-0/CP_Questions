#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(vector<vector<int>> &v, vector<int> &a, int i,int pc, int p, int k){
    if(pc==p){
        
    }
    if(i>=v.size()) return -1e8;
}

void solve()
{
    int n,p,k;
    cin>>n>>p>>k;
    vector<int> a(n);
    vector<vector<int>> v(n,vector<int>(p));
    for (int i = 0; i < n; i++)cin>>a[i];
    for (int i = 0; i < n; i++) for(int j = 0;j<p;j++) cin>>v[i][j];
    
}
signed main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
