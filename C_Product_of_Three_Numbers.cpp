#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    int a =0, b=0, c=0;
    for (int i = 2; i <= 32000; i++)
    {
        if(n%i==0){
            n/=i;
            if(a==0){
                a = i;
            }
            else if(b==0){
                b = i;
                if(n!=1&&n!=b&&n!=a){
                    c = n;
                    break;
                }
                else{
                    c=0;
                    break;
                }
            }
        }
    }

    if(a&&b&&c){
        cout<<"YES"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    else cout<<"NO"<<endl;
    
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
