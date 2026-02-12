#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    long long prod = 1;
    int p = INT_MIN;
    unordered_map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(v[i]%k==0) prod = 0;
        map[v[i]%k]++;
        p = max(p,v[i]%k);
    
        
    }

    if(prod==0) cout<<0<<endl;
    else if(k==2) cout<<1<<endl;
    else if(k==3||k==5) cout<<k-p<<endl;
    else{
        if(map[2]>1) cout<<0<<endl;
        else if(map[2]>0 && map[1]>0)  cout<<1<<endl;
        else if(map[1]>=2&&p!=3) cout<<2<<endl;
        else cout<<k-p<<endl;
    }

    
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
