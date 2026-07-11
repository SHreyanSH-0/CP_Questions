#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int one = 0;
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1') one++;
        else zero++;
    }
    for (int i = n-1; i>=0; i--)
    {
        if(s[i]=='1') one--;
        else if(one%2==1){
            cout<<"Alice"<<endl;
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(s[i]=='0') zero--;
        else if(zero%2==1) {
            cout<<"Alice"<<endl;
            return;
        }
    }
   cout<<"Bob"<<endl;    
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
