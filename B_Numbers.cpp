#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int rec(vector<int>&v, int i,int n,vector<int>&hold,bool started){
    if(i==n){
        for(int j=0;j<10;j++) if(v[j]>hold[j]) return 0;
        return 1;
    }
    int ans = 0;
    for(int j = 0;j<=9;j++){
        if(!started&&j==0){
            ans += rec(v,i+1,n,hold,0);
            continue;
        }
        hold[j]++;
        ans += rec(v,i+1,n,hold,1);
        hold[j]--;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(10),hold(10,0);
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        cin>>v[i];
        sum+=v[i];
    }

    if(sum>n) cout<<0<<endl;

    cout<<rec(v,0,n,hold,0);
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
