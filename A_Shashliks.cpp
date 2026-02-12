#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,a,b,x,y;
    cin>>n>>a>>b>>x>>y;
    if(n<a&&n<b) cout<<0<<endl;
    else{
        int ans = 0;
        if(x>y){
            if(n>=b){
                ans +=  (n-b+y)/y;
                n -= ans*y;
                if(n>=a){
                    ans += (n-a+x)/x;
                }
            }
            else{
                if(n>=a){
                    ans += (n-a+x)/x;
                }
            }
        }
        else if(y>x){
            if(n>=a){
                ans += (n-a+x)/x;
                n -= ans*x;
                if(n>=b){
                    ans += (n-b+y)/y;
                }
            }
            else{
                ans  += (n-b+y)/y;
            }
        }
        else{
            if(a>b){
                ans += (n-b+y)/y;
            }
            else{
                ans += (n-a+x)/x;
                
            }
        }
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
