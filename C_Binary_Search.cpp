#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define int long long

long long fact(int n) {
    long long result = 1;
    for(int i = 1; i <= n; i++) {
        result = result*i%mod;
    }
    return result;
}

void solve()
{
    int n, x, pos;

    cin>>n>>x>>pos;

    int left = 0, right = n;
    int less = x-1, more = n - x;
    long long ans = 1;

    while(left<right){
        int mid = (left+right)/2;
        if(mid>pos){
            if(more>0){
                ans*=(more);
                more--;
                ans = ans % mod;
            }
            else {
                ans = 0;
                break;
            }
            right = mid;
        }
        else if(mid<pos){
            if(less>0){
                ans*=(less);
                less--;
                ans = ans % mod;
            }
            else {
                ans = 0;
                break;
            }
            left = mid + 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    if(ans==0) {
        cout<<0<<endl;
        return;
    }
    else{
        ans = (ans*fact(less+more))%mod;
        cout<<ans<<endl;
    }

}
signed main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}