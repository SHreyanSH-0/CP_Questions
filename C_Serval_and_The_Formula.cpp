#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int a , b;
    cin>>a>>b;

    if(a==b){
        cout<<-1<<endl;
    }
    else if((a&b)==0){
        cout<<0<<endl;
    }
    else{
        if(a<b){
            a = b;
        }
        int hold = log2(a);
        long long hold2 = pow(2,hold+1);

        cout<<hold2-a<<endl;
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
