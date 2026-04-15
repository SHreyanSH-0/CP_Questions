#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int p,q;
    cin>>q>>p;

    for(int m=1;m<=100000;m++){
        if(p>=m*(m+1)){
            int p2 = p - (m*(m+1));

            if(m*q - p2 >= 0 &&(m*q-p2)%((2*m+1))==0){
                int n = q - 2*((m*q-p2)/((2*m+1)));
                cout<<m<<" "<<n + m<<endl;
                return;
            }
        }
        else if(q >= 2*(m*(m+1)-p)){
            int p2 = 0;
            int q2 = q - 2*(m*(m+1)-p);
            if(m*q2 >= 0&&(m*q2)%((2*m+1))==0){
                int n = q2 - 2*((m*q2)/((2*m+1)));
                cout<<m<<" "<<n+m<<endl;
                return;
            }
        }
    }

    cout<<-1<<endl;
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
