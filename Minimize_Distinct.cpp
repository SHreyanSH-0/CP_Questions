#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        s.insert(v[i]);
    }
    vector<int> hold,f;
    for(auto&it:s) hold.push_back(it);
    int prev = INT_MAX;
    for (int l = n; l>=1; l--)
    {
        int small = lower_bound(hold.begin(),hold.end(),l) - hold.begin();
        int ans = hold.size();
        if(small<hold.size()){
            if(small+3<hold.size()){
                if(hold[small]+2==hold[small+2]&&hold[small+1]+2==hold[small+3]){
                    ans-=2;
                }
                else if(hold[small]+2==hold[small+2]){
                    ans--;
                }
                else if(hold[small]+2==hold[small+1]){
                    ans--;
                }
            }
            else if(small+2<hold.size()){
                if(hold[small]+2==hold[small+2]){
                    ans--;
                }
                else if(hold[small]+2==hold[small+1]){
                    ans--;
                }
            }
            else if(small+1<hold.size()){
                if(hold[small]+2==hold[small+1]){
                    ans--;
                }
            }
        }
        // cout<<ans<<" "<<small<<endl;

        f.push_back(min(ans,prev));
        prev = min(prev,ans);
    }    
    for (int i = f.size()-1; i>=0; i--)
    {
        cout<<f[i]<<" ";
    }cout<<endl;
    
    

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
