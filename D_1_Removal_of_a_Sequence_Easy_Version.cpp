#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
void solve()
{
    int x,y,k;
    cin>>x>>y>>k;
    
    int high = 1e12, low = 1;
    int ans = -1;
    while(high>=low){
        int mid = (high+low)/2;
        int hold = mid;
        for(int i=0;i<x;i++){
            hold = hold - hold/y;
        }

        if(hold>=k){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
        
    }
    cout<<ans<<endl;
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
