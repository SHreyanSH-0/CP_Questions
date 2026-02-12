#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int s,k,m;
    cin>>s>>k>>m;
    if(s<=k){
        int ans = s - m%k;
        if(ans<0) cout<<0<<endl;
        else
        cout<<s - m%k<<endl;
    }
    else{
        int flip = m/k;
        int left = m%k;
        if(flip%2==0){
            int ans = s-m%k;
            if(ans<0) cout<<0<<endl;
            else
            cout<<s - m%k<<endl;
        }
        else{
            int ans = k-left;
            if(ans<0) cout<<0<<endl;
            else
            cout<<k - left<<endl;

        }
    }
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
