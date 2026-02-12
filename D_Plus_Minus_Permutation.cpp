#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    long long n,x,y;
    cin>>n>>x>>y;
    long long ans = 0;
    long long end = n;
    long long start = 1;
    if(x==y) cout<<0<<endl;
    else{

        long long a,b,c;
        a = n/x;
        b = n/y;
        long long g = __gcd(x,y);
        c= n/((x/g)*(y));
        a-=c;
        b -= c;
        ans = (a*(2*n-(a-1)))/2 - (b*(b+1))/2;
        cout<<ans<<endl;
    }
    
}
int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
