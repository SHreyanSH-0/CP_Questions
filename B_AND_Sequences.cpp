#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int fact(int n){
    int ans = 1;
    for (int i =1; i <= n; i++)
    {
        ans = (ans * i)%mod;
    }
    return ans;
    
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> map;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(i==0) a= v[i];
        else a = (a&v[i]);
        map[v[i]]++;
    }

    auto it = *map.begin();
    if(a == it.first){
        cout<<(((it.second * (it.second-1))%mod) * (fact(n-2)))%mod<<endl;
    }
    else cout<<0<<endl;

        
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
