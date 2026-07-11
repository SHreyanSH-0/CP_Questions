#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,x;
    cin>>n>>x;
    string ans(3*n , '1');
    int ones = x;
    int zeros = 3*n - x;
    
    if(zeros >= 2*n){
        for (int i = 0; i < zeros; i++)
        {
            ans[i] = '0';
        }
        
    }
    else{
        for (int i = 0; i < zeros/2; i++)
        {
            ans[i] = ans[i + n] = '0';
        }

        zeros = zeros%2;
        if(zeros){
            for (int i = 0; i < n; i++)
            {
                if(ans[i]=='1') {ans[i] = '0'; break;}
            }
            
        }
    }


    cout<<ans<<endl;
    
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
