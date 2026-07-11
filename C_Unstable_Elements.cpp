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
    map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        map[v[i]]++;
    }

    vector<pair<int,int>> hold;

    for(auto&[x,y]:map){
        hold.push_back({y,x});
    }

    sort(hold.begin(),hold.end());
    int total = n;
    n = hold.size();
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        while(hold[i].first - sum > 0){
            if(k >= total && (k-total)%(n-i) == 0){
                ans++;
                total -= (n-i)*(hold[i].first - sum);
                sum += (hold[i].first - sum);
                break;
            } 
            sum++;
            total -= (n-i);
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
