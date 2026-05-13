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
    map<int,int> count , ans;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++)
    {
        int hold = v[i];
        int ct = 0;
        while(hold>0){
            if(count[hold]==k){
                
            }
            else{
                count[hold]++;
                ans[hold] += ct;
            }
            hold/=2;
            ct++;
        }
    }   
    int fans = 1e8;
    for(auto&[x,y]:ans){
        if(count[x]==k) fans = min(fans,y);
    }
    cout<<fans<<endl;
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
