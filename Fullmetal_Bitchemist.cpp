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
    
    int ans = (n*(n+1))/2;

    map<int,int> map;
    map[0]++;

    for (int i = 0; i < n; i++)
    {
        if(i+1<n&&s[i]!=s[i+1]){
            int ct = 1;
            while(i+1<n&&s[i]!=s[i+1]){
                ct++;
                i++;
            }
            for(int j=0;j<ct;j++){
                ans = ans - ceil((ct-j)/2.0) + 1;
            }
        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int val;
        if(s[i]=='0') val = 1;
        else val = 2;

        sum += val;
        int m = sum%3;

        ans -= map[m];
        map[m]++;
    }
    
    

    cout<<ans<<endl;
    
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
