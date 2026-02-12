#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int dp[101][3];

int rec(vector<int>& v, int i, int prev){
    if(i==v.size()) return 0;

    if(dp[i][prev] != -1 ) return dp[i][prev];

    int r,g,c;
    g = c = 1e8;
    r = 1 + rec(v,i+1,0);

    if(v[i]==1){
        if(prev==1){
            c = 1 + rec(v,i+1,0);
        }
        else{
            c = rec(v,i+1,1);
        }
    }
    else if(v[i]==2){
        if(prev==2){
            g = 1 + rec(v,i+1,0);
        }
        else{
            g = rec(v,i+1,2);
        }
    }
    else if(v[i]==3){
        if(prev!=1){
            c = rec(v,i+1,1);
        }
        if(prev!=2){
            g = rec(v,i+1,2);
        }
    }
    return dp[i][prev] = min(r,min(g,c));
    
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<rec(v,0,0)<<endl;
    
}
int main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
