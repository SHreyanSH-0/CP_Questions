#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    int ans= 0;

    int ct = 0;

    int lastone = -k;

    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(i-lastone>=k) ans++;
            lastone = i;
        }

    }
    cout<<ans<<endl;
}
int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
