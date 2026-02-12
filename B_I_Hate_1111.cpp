#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    int x;
    cin>>x;
    
    for(int i=0;i<11&&(x-111*i>=0);i++){
        if((x-111*i)%11==0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;

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
