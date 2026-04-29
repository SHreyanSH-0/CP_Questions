#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            while(i<n&&s[i]=='1'){
                s[i] = '0';
                i++;
            }
            i--;
            s[i] = '1';   
        }
    }
    int prev = -1;    
    for(int i=n-1;i>0;i--){
        if(s[i]=='0'&&s[i-1]=='0'){
            prev = i-1;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            if(i+2<n&&s[i+2]=='0'){
                s[prev] = '1';
                s[i] = '0';
                prev -=2;
            }
        }
    }
    
    cout<<s<<endl;
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
