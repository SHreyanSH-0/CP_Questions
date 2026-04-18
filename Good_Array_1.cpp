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
    int hold = n+1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        set<int> s;
        map<int,int> map;
        for(int j=i;j<n;j++){
            map[v[j]]++;
            if(map[v[i]]==1){
                s.insert(v[j]);
            }
            else{
                s.erase(v[j]);
            }

            if(s.size()==0){
                v[j] = hold;
                s.insert(hold);
                hold++;
                ans++;
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
