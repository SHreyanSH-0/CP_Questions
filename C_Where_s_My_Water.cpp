#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n, h;
    cin>>n>>h;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    if(n==1){
        cout<<h-v[0]<<endl;
        return;
    }
    vector<vector<int>> water(n,vector<int>(n));
    vector<int> extra(n,0);
    for (int i = 0; i < n; i++)
    {
        int curr = v[i];
        int hold = 0;
        for(int j = i;j<n;j++){
            curr = max(curr, v[j]);
            hold += h - curr;
            water[i][j] = hold;
        }
        curr = v[i];
        hold = 0;
        for(int j = i-1;j>=0;j--){
            curr = max(curr, v[j]);
            hold += h - curr;
            water[i][j] = hold;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int maxi = v[i];
        int maxind = i;
        for (int j = i+1; j < n; j++)
        {
            
            int plus = water[j][maxind] - (h - maxi)*(j - maxind);
            if(v[j]>=maxi){
                maxi = v[j];
                maxind = j;
                plus = 0;
            }
            if(i==0){
                ans = max(ans,water[i][j-1] + water[j][n-1] + plus);
            }
            else{
                ans= max(ans, water[i][0] + water[i][j-1] + water[j][n-1] + plus);
            }
        }
        // cout<<endl;
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
