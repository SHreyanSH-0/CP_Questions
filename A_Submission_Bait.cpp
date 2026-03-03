#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        s.insert(v[i]);
    }
    vector<int> hold;

    for(auto &it : s){
        hold.push_back(it);
    }
    int ct = 0;
    sort(hold.rbegin(),hold.rend());
    for(int i=0;i<hold.size();i++){
        int m = hold[i];
        for(int j=0;j<n;j++){
            if(v[j]==m) ct++;
        }
        if(ct%2==1){
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
    
    
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
