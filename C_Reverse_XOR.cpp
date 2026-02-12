#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define int long long
void solve()
{
    int n;
    cin>>n;
    long long a = 0, b = 0;
    int hold = n;

    bool check = true;

    long long pow = 1;
    while(hold>0){
        if(hold%2==1){
            b = b<<1;
            if(check){
                a += pow;
                b = b|1;
                check = false;
            } 
            else{
                check = true;
            }        
        }
        else{
            b = b<<1;
            a += pow;
            b = b|1;
        }

        pow*=2;
        hold/=2;
    }
    int ct = log2(n)+ 1;
    while(ct<62 && (a^b) != n){
        b = b<<1;
        a += pow;
        b = b|1;
        ct++;
        pow*=2;
    }

    if((a^b)==n){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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
