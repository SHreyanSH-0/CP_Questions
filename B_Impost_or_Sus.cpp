#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    int last = 1e8;
    int n = s.size();

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'u'){
            if(i==0||i==n-1){
                ans++;
                s[i] = 's';
            } 
            else{
                if(s[i-1]!='s') ans++;
                if(s[i+1]!='s') ans++;
                s[i-1] = 's';
                s[i+1] = 's';
            }
        } 
    }
    
    
    cout<<ans<<endl;
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
