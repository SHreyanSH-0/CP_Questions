#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int b,g,x,y,n;
    cin>>b>>g>>x>>y>>n;
    int low = 1, high = min(b/x,g/y);

    while(low<=high){
        int mid = (low + high)/2;
        int hold = (n - x - y)*mid;
        if(hold >= b - x*mid + (g - y*mid) ){
            high = mid-1;
        }
        else low = mid + 1;
    }
    if(low == min(b/x,g/y)+1) cout<<-1<<endl;
    else
    cout<<low<<endl;

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
