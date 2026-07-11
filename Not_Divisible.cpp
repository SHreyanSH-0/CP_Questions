#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int N = n + 1;
    vector<int> ct(n+1);
    for (int i = 0; i < n; i++)
    {
        ct[a[i]]++;
    }


    for (int i = 1; i <= n; i++)
    {
        if(ct[i] > n-1) {
            cout<<-1<<endl;
            return;
        }
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    vector<int> ans(n);    
    set<int> nobody;
    ct = vector<int>(n+1,0);
    for (int i = n-1; i >=0 ; i--)
    {
        int hold = N - a[i];
        ct[hold]++;
        nobody.insert(hold);
    }
    vector<int> vis(n+1,0);
    for (int i = 0; i < n; i++)
    {
        int hold = N - a[i];
        
        vector<int> r;
        bool check = true;
        for(auto &it : nobody){
            if(vis[it]) r.push_back(it);
            else if(it == hold) continue;
            else{
                ans[i] = it;
                // ans.push_back(it);
                r.push_back(it);
                vis[it] = true;
                check = false;
                break;
            }
        }
        for (int i = 0; i < r.size(); i++)
        {
            nobody.erase(r[i]);
        }

        ct[hold]--;
        if(ct[hold] == 0) nobody.erase(hold);
        

        if(check){
            vector<int> rem;
            for(auto &it : s){
                if(vis[it]) rem.push_back(it);
                else if(it == hold) continue;
                else{
                    ans[i] = it;
                    // ans.push_back(it);
                    rem.push_back(it);
                    vis[it] = true;
                    break;
                }
            }
            for (int i = 0; i < rem.size(); i++)
            {
                s.erase(rem[i]);
            }
        }
    }
    // if(ans.size() < n){
    //     cout<<-1<<endl;
    //     return;
    // }

    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    
    cout<<endl;
    
    
    
    
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
