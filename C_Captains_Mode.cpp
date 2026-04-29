#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int dp[20][(1<<20)];
int rec(vector<vector<int>>&v, vector<int> &hero, int i, int bit){
    if(i>=v.size()) return 0;
    if(dp[i][bit]!=-1) return dp[i][bit];
    if(v[i][0]==0) {
        if(v[i][1]==0){
            int ans = -1e8;
            for(int j=0;j<v.size();j++){
                if(!((1<<j)&bit)){
                    ans = max(ans,hero[j] + rec(v,hero,i+1,bit|(1<<j)));
                    break;
                }
            }
            return dp[i][bit] = ans;
        }
        else{
            int ans = 1e8;
            for(int j=0;j<v.size();j++){
                if(!((1<<j)&bit)){
                    ans = min(ans,-hero[j] + rec(v,hero,i+1,bit|(1<<j)));
                    break;
                }
            }
            return dp[i][bit] = ans;
        }
    }
    else{
        if(v[i][1]==0){
            int ans = -1e8;
            for(int j=0;j<v.size();j++){
                if(!((1<<j)&bit)){
                    ans = max(ans,rec(v,hero,i+1,bit|(1<<j)));
                }
            }
            return dp[i][bit]= ans;
        }
        else{
            int ans = 1e8;
            for(int j=0;j<v.size();j++){
                if(!((1<<j)&bit)){
                    ans = min(ans, rec(v,hero,i+1,bit|(1<<j)));
                }
            }
            return dp[i][bit] = ans;
        }

    }
    return 0;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> hero(n);
    for (int i = 0; i < n; i++)
    {
        cin>>hero[i];
    }
    sort(hero.rbegin(),hero.rend());
    int m;
    cin>>m;
    vector<vector<int>> v(m,vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        int a;
        char c;
        cin>>c>>a;
        if(c=='p') v[i] = {0,a-1};
        else v[i] = {1,a-1};
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(v,hero,0,0);
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
