#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    string s= to_string (n);
    if(s.size()==1){
        if(n%2==0) cout<<-1<<endl;
        else cout<<0<<endl;
        return;
    }
    else if((s[s.size()-1]-'0')%2==1){
        cout<<0<<endl;
        return;
    }
    int m = 0;

    for(int i=0;i<s.size();i++){
        if((s[i]-'0')%2==1){
            cout<<1<<endl;
            return;
        }
        m = max(m,(ll)(s[i]-'0'));
    }
    if(m>s[s.size()-1]-'0') cout<<2<<endl;
    else cout<<3<<endl;
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
