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
        hold.push_back({x,y});
    }
    sort(hold.rbegin(),hold.rend());

    vector<vector<int>> v1;
    for (int i = 0; i < hold.size(); i++)
    {
        int a = hold[i].first;
        int b = hold[i].second;
        vector<int> v2 = {b};
        if (i+1 < hold.size() && hold[i].first - hold[i+1].first <= k)
        {
            v2.push_back(hold[i+1].second);
            i++;
        }
        v1.push_back(v2);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        int sum = v1[i][0];
        if(sum%2==0){
            cout<<"YES"<<endl;
            return;
        }
        for (int j = 1; j < v1[i].size(); j++)
        {
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
