#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    map<int,int> map;
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        map[v[i]]++;
    }

    int x2 = v[n/2];
    int x1 = v[n/2 - 1];

    for(int i=0;v[i]<=x1;i++){
        // x1 - d = p1
        int d = x1 - v[i];

        if(map.find(x2 + d)==map.end()){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
    
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
