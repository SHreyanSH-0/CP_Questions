#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1,0),b(n+1,0);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i+1];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i+1];
    }

    queue<pair<int,int>> pq;
    pq.push({0,n});

    vector<pair<int,int>> par(n+1);

    set<int> pos;

    for (int i = 0; i <= n; i++)
    {
        pos.insert(i);
    }
    

    vector<int> dist(n+1, 1e12);
    dist[n] = 0;
    while (!pq.empty())
    {
        auto it = pq.front();
        pq.pop();

        int k = it.first;
        int d = it.second;
        if(dist[d] < k) continue;
        if(d==0) {
            cout<<k<<endl;
            int currd = 0, currk = k;
            vector<int> hold;
            while(currk>0){
                hold.push_back(currd - par[currd].second);
                currd = par[currd].first;
                currk--;
            }
            for(int i=hold.size()-1;i>=0;i--) cout<<hold[i]<<" ";
            return;
        }

        int maxJump = a[d];
        vector<int> rem = {d};
        auto idx = pos.lower_bound(d - maxJump);

        while(true){
            if(idx==pos.end()) break;
            int val = *idx;
            if(val >= d) break;
            rem.push_back(val);

            if(dist[val  + b[val]] > k + 1){
                dist[val + b[val]] = k + 1;
                pq.push({k+1, val + b[val]});
                par[val + b[val]].first = d;
                par[val + b[val]].second = b[val];
            }

            idx++;
        }

        for(int i=0;i<rem.size();i++) pos.erase(rem[i]);

        
    }

    cout<<-1<<endl;
    


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
