#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
   
    if(n%2==0&&(n/2)%2==0){
        cout<<"YES"<<endl;
    }
    else if(n%2==0&&(n/2)%2==1){
        n = n/2;
        int a = (3^n) + 1;
        if(a==1||n==1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        return;
    }
    else{
        int a = (3^n) + 1;
        if(a==1||n==1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        return;
    }
    
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
