#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    
    for(int k = 2;k<=sqrt(n);k++){
        int hold = n*(k-1) + 1;

        while(hold%k==0){
            hold/=k;
        }
        if(hold==1) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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
