#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int ans = 0;
int rec(vector<vector<int>>&v,vector<int>&val,int node, int par, bool check){
    int sum = 0;
    if(v[node].size()==1 && v[node][0] == par) return 1; 
    vector<int> hold;
    bool nextCheck = true;
    int b = val[node];
    int sq = sqrt(b);
    if(b == sq*sq){
        nextCheck = false;
    }
    if(!nextCheck){
        for(auto&it : v[node]){
            if(it==par) continue;
            int a = rec(v,val,it,node,nextCheck);
            sum += a;
            hold.push_back(a);
        }
        hold.push_back(v.size()-2 - sum);
    
        
        int sum2 = 1;
        for (int i = 0; i < hold.size(); i++)
        {
            sum2+=hold[i];
        }

        int n = hold.size();
        vector<int> pref(n,0), pref2(n,0);
        pref[0] = hold[0];
        for(int i=1;i<n;i++) pref[i] = pref[i-1] + hold[i];
        pref2[0] = hold[0]*pref[0];
        for(int i=1;i<n;i++) pref2[i] = pref2[i-1] + hold[i]*pref[i];

        // for (int i = 0; i < n; i++)
        // {
        //     cout<<pref[i]<<" ";
        // }cout<<endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<pref2[i]<<" ";
        // }cout<<endl;
        
        

        // for (int i = 0; i < hold.size(); i++)
        // {
        //     int s = sum2;
        //     for (int j = i+1; j < hold.size(); j++)
        //     {
        //         ans += hold[i]*hold[j]*(s - hold[i] - hold[j]);
        //         s-=hold[j];
        //     }
        //     sum2 -= hold[i];
        // }

        for (int i = 0; i < n-1; i++)
        {
            int j = i+1;
            ans += hold[i] * ((pref[n-1] + 1) * (pref[n-1] - pref[i])  - (pref2[n-1] - pref2[i]));
        }
        
    }
    else{
        for(auto&it : v[node]){
            if(it==par) continue;
            int a = rec(v,val,it,node,nextCheck);
            sum += a;
        }
    }

    return sum + 1;
}

void solve()
{
    ans = 0;
    int n;
    cin>>n;
    vector<int> val(n+1);
    for (int i = 0; i < n; i++)
    {
        cin>>val[i+1];
    }
    vector<vector<int>> v(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int start = 0;
    for (int i = 1; i <= n; i++)
    {
        if(v[i].size()>=2) start = i;
    }
    
    rec(v,val,start,-1, true);

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
