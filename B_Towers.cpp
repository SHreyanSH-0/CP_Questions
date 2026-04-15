#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    set<pair<int,int>> ms;
    for(int i=0;i<n;i++){
        cin>>v[i];
        ms.insert({v[i],i+1});
    } 
    int ans = 0;
    vector<pair<int,int>> hold;
    for(int i=0;i<k;i++){
        auto [a,idx1] = *ms.begin();
        auto [b,idx2] = *ms.rbegin();
        if(b>a){
            ms.erase({a,idx1});
            ms.erase({b,idx2});
            ms.insert({a+1,idx1});
            ms.insert({b-1,idx2});
            hold.push_back({idx2,idx1});
        }
        else break;
        ans = (*ms.rbegin()).first - (*ms.begin()).first;
    }


    cout<<ans<<" "<<hold.size()<<endl;
    for (int i = 0; i <hold.size(); i++)
    {
        cout<<hold[i].first<<" "<<hold[i].second<<endl;
    }
    
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
