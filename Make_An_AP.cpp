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
    int d = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(i>0){
            d = min(d, v[i] - v[i-1]);
        }
    }
    int a = v[0];
    int ans = 0;
    while (d>=1)
    {
        bool check = true;
        for(int i=0;i<n;i++){

            if((v[i]-a)%d!=0){
                check = false;
                break;
            }
        }
        if(check){
            int n1 = (v[n-1] - a)/d + 1;
    
            ans = n1 - n;
            break;
        }
        d--;
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
