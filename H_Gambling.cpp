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
    for(int i=0;i<n;i++) cin>>v[i];
    map<int,vector<int>> map;
    for(int i=0;i<n;i++) map[v[i]].push_back(i);
    int a1 = v[0],l = 0,r = 0;
    int ans = 1;
    for(auto &[x,a]:map){
        int freq = 1;
        int last = a[0];

        for(int i=1;i<a.size();i++){
            freq++;
            int ct = 2*freq - ((a[i] - last + 1));
            if(2*freq<=a[i] - last + 1){
                freq = 1;
                last = a[i];
                continue;
            }
            if(ct>ans){
                ans = ct;
                a1 = x;
                l = last;
                r = a[i];
            }
                                   
        }
    }
    cout<<a1<<" "<<l+1<<" "<<r+1<<endl;

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
