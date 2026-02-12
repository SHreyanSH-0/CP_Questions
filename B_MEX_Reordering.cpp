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

    sort(v.begin(),v.end());
    set<int> pre;
    for (int i = 0; i < n; i++)
    {
        pre.insert(v[i]);
        set<int> suff;
        for(int j=i+1;j<n;j++) suff.insert(v[j]);
        int a = 0;
        int b = 0;
        for(auto &it:suff){
            if(it==a) a++;
            else break;
        }
        for(auto &it:pre){
            if(it==b) b++;
            else break;
        }
        if(a==b) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    
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
