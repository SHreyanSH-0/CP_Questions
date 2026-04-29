#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int l,r;
    cin>>l>>r;
    int a = l, b = r;
    int hold = r;
    int ct = 0;
    while(hold>0){
        hold/=2;
        ct++;
    }
    ct--;
    for (int i = ct; i >=0; i--)
    {
        int hold1 = (a & (1LL<<(i))) ;
        int hold2 = (b & (1LL<<(i))) ;
        if(hold1&&hold2){
            hold1 = (1LL<<(i));
            hold2 = (1LL<<(i));
            if((hold1^a) >= l){
                a = (hold1^a);
            }
            else if((hold2^b) >=l){
                b = (hold1^b);
            }
        }
        else if(hold1){
            
        }
        else if(hold2){
            
        }
        else{
            hold1 = (1LL<<(i));
            hold2 = (1LL<<(i));
            if((hold1^a) <=r){
                a = (hold1^a);
            }
            else if((hold2^b) <=r){
                b = (hold1^b);
            }
        }
        // cout<<a<<" "<<b<<endl;
    }
    cout<<(a^b)<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
