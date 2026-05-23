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
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    unordered_map<int,int> map1,count;
    map1.reserve(40*n);
    count.reserve(40*n);
    
    for (int i = 0; i < n; i++)
    {

        if(v[i]==1){
            count[1]++;
            map1[1] +=0;
            map1[2]++;
            count[2]++;
            continue;
        }
        int hold = v[i];
        map1[hold]+=0;
        count[hold]++;
        int ct = 0;
        while(hold>1){
            if(hold%2==1){
                hold++;
            }
            else hold/=2;
            ct++;
            
            count[hold]++;
            map1[hold]+=ct;
        }
    }
    int ans = 1e8;
    for(auto&[x,y] : count){
        if(y==n)
        ans = min(ans,map1[x]);
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
