#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int dp[20][(1<<16)];

int rec(vector<vector<int>> &v, int music , int artist, int take,int left){
    int ans = __builtin_popcountll(left);
    
    if(dp[take+1][left] != -1) return dp[take+1][left];

    for(int j = 0; j<v.size();j++){
        if(v[j][2] == 1) continue;
        if(music==0&&artist==0){
            v[j][2] = 1;
            ans = min(ans,rec(v,v[j][0],v[j][1],j, ((1<<j)^left)));
            v[j][2] = 0;
        }
        else if(v[j][0]==music||v[j][1]==artist){
            v[j][2] = 1;
            ans = min(ans,rec(v,v[j][0],v[j][1],j, ((1<<j)^left)));
            v[j][2] = 0;
        }
    }

    return dp[take+1][left] = ans;
}

void solve()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<vector<string>> v(n);
    string a,b;
    a = b = "0";

    unordered_map<string,int> m1;

    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        v[i] = {a,b,"0"};
    }

    vector<vector<int>>h(n);

    int count = 1;
    for(int i=0;i<n;i++){
        if(m1.find(v[i][0])==m1.end()){
            m1[v[i][0]] = count++;
        }
    }
    
    for(int i=0;i<n;i++){
        if(m1.find(v[i][1])==m1.end()){
            m1[v[i][1]] = count++;
        }
    }

    for(int i=0;i<n;i++){
        h[i] = {m1[v[i][0]],m1[v[i][1]],0};
    }

    int hold = (1<<n)-1;
    cout<<rec(h,0,0,-1,hold)<<endl;    
}
int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
