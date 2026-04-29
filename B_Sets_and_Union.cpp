#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> s(n); 
    map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        for (int j = 0; j < a; j++)
        {
            int b;
            cin>>b;
            s[i].push_back(b);
            map[b]++;
        }
    }
    int ans = 0;

    for(auto &[x,y]:map){
        set<int> s1;
        for (int i = 0; i < n; i++)
        {
            bool check = true;
            for (int j = 0; j < s[i].size(); j++)
            {
                if(s[i][j]==x) check = false;
            }
            if(check) {
                for (int j = 0; j < s[i].size(); j++)
                {
                    s1.insert(s[i][j]);
                }
                
            }
            
        }

        int hold = s1.size();
        ans = max(ans,hold);
        
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
