#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
void solve()
{
    int a,b;
    cin>>a>>b;

    int digit = log2(a) + 1;
    if(1){
        int one = 0, two = 0;
        int p=1;
        int hold = a;
        while (a>0)
        {
            if(a%2==0){
                one+=p;
            }
            a/=2;
            p*=2;
        }
        a = hold^one;
        if(b>a){
            cout<<-1<<endl;
        }
        else{
            
            p = 1;
            while (hold>0)
            {
                if(b%2==0){
                    two+=p;
                }
                b/=2;
                p*=2;
                hold/=2;
            }
            
            
            cout<<2<<endl;
            cout<<one<<" "<<two<<endl;
        }
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
