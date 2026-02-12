#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,n});
    unordered_map<int,int> map;

    while(!q.empty()){
        int val = q.top().second;
        int t = q.top().first;
        
        q.pop();
        if(val==k) {
            cout<<t<<endl;
            return;
        }
        if(val==0||val==1) continue;
        if(val%2==0){
            if(map.find(val/2)==map.end())
            q.push({t+1,val/2});
            map[val/2]++;
        } 
        else {
            if(map.find(val/2 + 1)==map.end())
            q.push({t+1,val/2 + 1});
            if(map.find(val/2)==map.end())
            q.push({t+1,val/2});
            map[val/2+1]++;
            map[val/2]++;
        }
    }
    cout<<-1<<endl;
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
