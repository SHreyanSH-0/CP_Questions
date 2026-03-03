#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(2));
    vector<vector<int>> shop(m,vector<int>(2));
    priority_queue<pair<int,int>> pq;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;
    int ans = 0;
    for (int i = 0; i < n; i++)
    { 
        cin>>v[i][0]>>v[i][1];
        if(v[i][1]>0)
        pq.push({v[i][0],v[i][1]});
        ans = max(ans,v[i][0]);
    }
    vector<int> hold(n+1,0);
    
    for (int i = 0; i < m; i++)
    {
        cin>>shop[i][0]>>shop[i][1];
    }
    int sum = 0;
    for(int i=1;i<=n;i++){

        while(!pq2.empty()&&pq2.top().first<i) {
            sum -= pq2.top().second;
            pq2.pop();
        }

        while(!pq.empty()){
            if(pq2.size()==i) break;
            if(pq.top().second<i) pq.pop();
            else{
                pq2.push({pq.top().second,pq.top().first});
                sum += pq.top().first;
                pq.pop();
            }
        }
        hold[i] = max(hold[i-1],sum);
    }

    while (!pq.empty()) {
        pq.pop();
    }
    while (!pq2.empty()) {
        pq2.pop();
    }

    for (int i = 0; i < n; i++)
    { 
        if(v[i][1]>0)
        pq.push({v[i][0],v[i][1]});
    }

    sum = 0;
    for(int i=1;i<=n;i++){

        while(!pq2.empty()&&pq2.top().first<i) {
            sum -= pq2.top().second;
            pq2.pop();
        }

        while(!pq.empty()){
            if(pq2.size()==i+1) break;
            if(pq.top().second<i) pq.pop();
            else{
                pq2.push({pq.top().second,pq.top().first});
                sum += pq.top().first;
                pq.pop();
            }
        }
        ans = max(ans,sum);
    }

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans,hold[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int idx = shop[i][1];

        if(idx==0) cout<<max(ans,shop[i][0])<<" ";
        else cout<<max(ans,shop[i][0] + hold[idx])<<" ";

    }cout<<endl;    
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
