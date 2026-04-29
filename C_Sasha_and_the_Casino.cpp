#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int k,x,a;
    cin>>k>>x>>a;
    int loss = 1;
    a--;
    if(a==0) {
        cout<<"NO"<<endl;
        return;
    }
    for (int i=0;i<x;i++)
    {
        int hold = (ceil((double)loss/(k-1)));
        if(loss%(k-1)==0) hold++;
        if(a < hold){
            cout<<"NO"<<endl;
            return;
        }
        a -=hold;
        loss += hold;
    }
    
    cout<<"YES"<<endl;

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
