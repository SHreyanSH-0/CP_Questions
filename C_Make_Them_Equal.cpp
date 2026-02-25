#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    char c;
    string s;
    cin>>n>>c>>s;
    int check = 0;
    for(int i=0;i<n;i++) if(s[i]==c) check++;
    if(check==n) {
        cout<<0<<endl;
    }
    else{
        for (int i = 1; i <= n; i++)
        {
            if(s[i-1]==c&&2*i>n){
                cout<<1<<endl<<i<<endl;
                return;
            }
        }
        
        if(s[n-1]==c&&s[n-2]==c){
            cout<<1<<endl<<n<<endl;
        }   
        else if(s[n-1]==c){
            cout<<1<<endl<<n<<endl;
        }
        else if(s[n-2]==c){
            cout<<1<<endl<<n-1<<endl;
        }
        else{
            cout<<2<<endl<<n <<" "<< n-1<<endl;
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
