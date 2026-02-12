#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n), b(m);


    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    string s;
    cin>>s;
    vector<pair<int,int>> left(n),right(n);
    int alive = n;
    for (int i = 0; i < n; i++)
    {
        int ind = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
        int ind2 = ind-1;
        
        if(ind<m){
            right[i] = {abs(a[i] - b[ind]),i};
        }
        else right[i] = {1e16,i};
        if(ind2>=0&&ind2<m) left[i] = {abs(a[i] - b[ind2]),i};
        else left[i] = {1e16,i};
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    
    int start = 0;
    int lp = 0, rp = 0;
    vector<bool> vis(n,false);
    for (int i = 0; i < k; i++)
    {
        if(alive>0){
            if(s[i]=='L') start--;
            else start++;
            if(start<0){
                while(lp<n&&left[lp].first<=abs(start)) {
                    if(vis[left[lp].second]) {lp++; continue;}
                    vis[left[lp].second] = true;
                    alive--;
                    lp++;
                }
            }
            else{
                while(rp<n&&right[rp].first<=abs(start)) {
                    if(vis[right[rp].second]){rp++; continue;}
                    vis[right[rp].second] = true;
                    alive--;
                    rp++;
                }
            }
        }
        cout<<max(alive,0LL)<<" ";
    }
    cout<<endl;
    
    



}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
