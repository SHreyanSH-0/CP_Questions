#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    
    if(n%2==1){
        cout<<1<<" ";
        int a = 2, b = 3;
        for (int i = 0; i < n/2; i++)
        {
            if(i==0){
                cout<<a<<" "<<1<<" "<<1<<" "<<b<<" "<<a<<" "<<b<<" "<<b<<" "<<a<<" "<<a<<" "<<b<<" ";
            }
            else
            cout<<a<<" "<<b<<" "<<a<<" "<<b<<" "<<b<<" "<<a<<" "<<a<<" "<<b<<" ";
            a+=2;
            b+=2;
        }cout<<1<<endl;
    }
    else{
        int a = 1, b = 2;
        for (int i = 0; i < n/2; i++)
        {
            cout<<a<<" "<<b<<" "<<a<<" "<<b<<" "<<b<<" "<<a<<" "<<a<<" "<<b<<" ";
            a+=2;
            b+=2;
        }cout<<endl;
        
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
