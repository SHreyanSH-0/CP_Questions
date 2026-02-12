#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> p(n), a(n);
    map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
        map[p[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int front = 0;
    int prev = -1;
    for(int i=0;i<n;i++){
        int ind = map[a[i]];
        if(ind<front){
            cout<<"NO"<<endl;
            return;
        }
        front = max(front,ind);
    }
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
