#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>s;
    n = s.size();
    int ans = 0;
    vector<int> a(n+1),b(n+1);
    a[0] = 0;
    b[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i-1] + (s[i-1] == 'a');
        b[i] = b[i-1] + (s[i-1] == 'b');
    }
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int one = 0,two=0,three=0;
            if(i>0){
                one = b[i];
            }
            if(j>0){
                if(i>0){
                    two = a[j] - a[i];
                }
                else{
                    two =  a[j];
                }
            }

            three = b[n] - b[j+1];
            ans = max(ans,n - one - two - three);
        }
        
    }
    cout<<ans;
    
}
signed main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
