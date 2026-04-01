#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = __gcd(x,a[i]);
    }
    int ans =0;
    
    for (int i = 0; i < n; i++)
    {
        if(i==0){
            int hold = __gcd(a[i],a[i+1]);
            if(a[i]!=hold){
                a[i] = hold;
                ans++;
            }
        }
        else if(i==n-1){
            int hold = __gcd(a[i],a[i-1]);
            if(a[i]!=hold){
                a[i] = hold;
                ans++;
            }
        }
        else{
            int a1 = __gcd(a[i],a[i+1]);
            int b1 = __gcd(a[i],a[i-1]);
            int hold = __gcd(a1,b1);
            hold = (a1/hold)*b1;
            if(a[i]!=hold){
                a[i]= hold;
                ans++;
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
