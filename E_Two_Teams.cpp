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
    set<int> s;
    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < n; i++)
    {
        /* code */cin>>v[i];
        pq.push({v[i],i});
        s.insert(i);
    }

    vector<int> vis(n,0);
    int turn = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(vis[it.second]) continue;
        vis[it.second] = turn+1;
        auto i = s.find(it.second);
        int ct = 0;
        vector<int> hold;
        hold.push_back(*i);
        auto j = i;
        j--;
        while(ct<k&&j!=s.end()){
            hold.push_back(*j);
            vis[*j] = turn + 1;
            ct++;
            j--;
        }
        ct = 0;
        j = i;
        j++;
        while(ct<k&&j!=s.end()){
            vis[*j] = turn + 1;
            hold.push_back(*j);
            ct++;
            j++;
        }

        for (int j = 0; j < hold.size(); j++)
        {
            s.erase(hold[j]);
        }       

        turn = (turn + 1)%2;
    }    
    for (int i = 0; i < n; i++)
    {
        cout<<vis[i];
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
