#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(k);
    for(int i=1;i<=k;i++){
        v[i-1] = i;
    }
    vector<int> ans(n,0);
    int idx = 0;
    int ind = k-1;
    while(k>0){
        if(idx%2==0){
            for(int i=0;i<n && ind>=0;i++){
                ans[i] += v[ind--];
                k--;
            } 
        }
        else{
            for(int i=n-1;i>=0 && ind>=0;i--){
                ans[i] += v[ind--];
                k--;
            } 
        }
        idx++;
    }

    cout<<(*max_element(ans.begin(),ans.end()))<<endl;
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
