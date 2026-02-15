#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    if(n==1) cout<<k<<endl;
    else if(n%k==0) cout<<1<<endl;
    else{

        int low = 2, high = k;
        while(low<=high){
            int mid = (low+high)/2;
            int hold = (n*mid)%k;
            if(hold<=(n-1)*mid) high = mid-1;
            else low = mid+1;
        }
        cout<<low<<endl;
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
