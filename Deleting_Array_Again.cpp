#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),c(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;


    for (int i = 0; i < n; i++)
    {
        q.push({c[i],i});
    }
    int ans = 0;
    int node = n;
    int prev = n;
    set<int> used;
    while(node>0){
        int ind = q.top().second;
        int val = q.top().first;
        q.pop();
        if(used.find(ind)!=used.end()) continue;

        for(int i =ind;i<prev;i++){
            ans += val*a[i];
            used.insert(i);
            node--;
        }
        prev = ind;
    }
    cout<<ans<<endl;
    
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
