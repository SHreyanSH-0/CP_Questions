#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    long long n, p;
    cin>>n>>p;
    int ans= INT_MAX;
    for (int i = 1; i < 54; i++)
    {
        int hold = 0;
        int num = n - i*p;
        int hold2 = num;
        while(num>0){
            hold += num%2;
            num/=2;
        }
        if(hold!=0){
            if((hold<i&&i-hold<hold2)||hold==i){
                ans = min(ans,i);
            }
        }
    }
    if(ans==INT_MAX) cout<<-1<<endl;
    else
    cout<<ans<<endl;
    
}
int main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
