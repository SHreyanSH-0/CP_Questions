#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;

    string s = to_string(n);

    int d = s.size();

    int x = n%12;

    int a = x;
    int b = n - x;

    if(a<=9){
        cout<<a<<" "<<b<<endl;
    }
    else{
        if(a==10){
            if(b>=12){
                cout<<a + 12<<" "<<b - 12<<endl;
            }
            else cout<<"-1"<<endl;
        }
        else if(a==11){
            cout<<a<<" "<<b<<endl;
        }
    }
    
    

    
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
