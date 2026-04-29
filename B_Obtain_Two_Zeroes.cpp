#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int a,b;
    cin>>a>>b;
    if((a==0&&b!=0)||(a!=0&&b==0)){
        cout<<"No\n";
        return;
    }
    if((2*a-b)%3==0){
        int x = (2*a-b)/3;
        int a2 = a - 2*x;
        int b2 = b - x;
        if(2*a2==b2&&a2>=0&&b2>=0&&x>=0){
            cout<<"YES\n";
            return;
        }
    }
    else if((2*b-a)%3==0){
        int x = (2*b-a)/3;
        int a2 = a - x;
        int b2 = b - 2*x;
        if(a2==2*b2&&a2>=0&&b2>=0&&x>=0){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";
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
