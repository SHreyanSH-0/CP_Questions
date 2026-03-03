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
    vector<pair<int,int>> vp;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        vp.push_back({0,v[i]});
    }

    int ans = 0;
    vector<bool> b(n+1,false);
    vp.push_back({1,1});
    for (int i = 0; i < n; i++)
    {
        if(vp[i].second - vp[i].first > 2) ans++;
        else{
            if(vp[i].first>=vp[i].second) continue;
            if(i==n) ans++;
            else if(vp[i].second - vp[i].first <= 2){
                ans ++;
                
                if(v[i+1]>4) continue;
                else {
                    if(vp[i].first==0){
                        if(v[i+1]==1||v[i+1]==2) vp[i+1].second = 0;
                        else if(v[i+1]==3||v[i+1]==4) vp[i+1].first = 2;
                    }
                    else{
                        if(v[i+1]==3||v[i+1]==4) vp[i+1].second = 2;
                    }
                }
                
            }
            
        }
    }
    

    cout<<ans<<endl;
    
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
