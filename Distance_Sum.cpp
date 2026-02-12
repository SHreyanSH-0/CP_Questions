#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
vector<int> fun(int n, int p){
    vector<int> po(n+1);
    int hold = 1;
    for (int i = 0; i <= n; i++)
    {
        po[i] = hold;
        hold = hold*n%p;
    }
    return po;
    
}

void solve()
{
    int n,p;
    cin>>n>>p;
    vector<int> po = fun(n,p);
    int ans = 2*po[n-1];
    for (int i = 2; i < n; i++)
    {
        for(int j = 2;j<n;j++){
            int hold =  
            
        }
    }
    
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
