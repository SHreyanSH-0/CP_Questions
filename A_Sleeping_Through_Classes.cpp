#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    int ans = 0;
    for(int i=0;i<n;){
        if(s[i]=='1'){
            i++;
            int ct = 0;
            while(i<n&&ct<k&&s[i]=='0'){
                ct++;
                i++;
            }
        }
        else{
            ans++;
            i++;
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
