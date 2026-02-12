#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    int n = s.size();

    int ans = INT_MAX;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            int ct = 0;
            int next = i;
            for(int ind=0;ind<n;ind++){
                if(next!=s[ind]-'0'){
                    ct++;
                }
                else {
                    if(next==i) next = j;
                    else next = i;
                }
            }
            if((n-ct)%2==1&&i!=j) ct++;
            ans = min(ans,ct);
            ct = 0;
            next = j;
            for(int ind=0;ind<n;ind++){
                if(next!=s[ind]-'0'){
                    ct++;
                }
                else {
                    if(next==i) next = j;
                    else next = i;
                }
            }
            if((n-ct)%2==1&&i!=j) ct++;
            ans = min(ans,ct);
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
