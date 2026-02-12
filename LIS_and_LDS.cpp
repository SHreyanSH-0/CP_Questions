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
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int dec = 0, inc = 0;
    vector<int> in,d;
    for(int i=0;i<n;i++){
        if(v[i]>1){
            dec++;
            inc++;
            in.push_back(i);
            d.push_back(i);
        }
        else{
            if(inc>=dec){
                dec++;
                d.push_back(i);
            }
            else{
                inc++;
                in.push_back(i);
            }
        }
    }

    vector<int> a;
    for(int i=0;i<(in.size());i++){
        a.push_back(in[i]);
    }
    for(int i=d.size()-1;i>=0;i--){
        a.push_back(d[i]);
    }
    
    n = a.size();
    int ans = 0;
    int ct = 1;
    for(int i=0;i<n-1;i++){
        if(a[i]<a[i+1]){
            ct++;
        }
    }
    ans = ct;
    ct = 1;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            ct++;
        }
    }
    ans = min(ans,ct);
    a.clear();
    for(int i=d.size()-1;i>=0;i--){
        a.push_back(d[i]);
    }
    
    for(int i=0;i<(in.size());i++){
        a.push_back(in[i]);
    }
    
    n = a.size();
    
    int ans2 = 0;
    ct = 1;
    for(int i=0;i<n-1;i++){
        if(a[i]<a[i+1]){
            ct++;
        }
    }
    ans2 = ct;
    ct = 1;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            ct++;
        }
    }
    ans2 = min(ans2,ct);
    cout<<max(ans,ans2)<<endl;
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
