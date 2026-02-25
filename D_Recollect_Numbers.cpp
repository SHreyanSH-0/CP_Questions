#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    
    if(k>=2*n||k<n) cout<<"NO"<<endl;
    else{
        vector<int> ans;
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++){
            ans.push_back(i);
            ans.push_back(i);
        }
        int j = 1;
        for (int i = n; i < k; i++)
        {
            swap(ans[j],ans[j+1]);
            j+=2;
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }cout<<endl;
    }

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
