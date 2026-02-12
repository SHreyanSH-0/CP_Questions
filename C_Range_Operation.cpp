#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }   
    int sum = 0;
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += v[i-1];
        prefix[i] = sum;
    }
    int ans = max(prefix[n] - prefix[0], n*(n+1));
    int j = 0;
    int hold = 0;

    for(int i=0;i<n;i++){
        if(hold<prefix[i] - ((i+1)*(i+1)) + (i+1)){
            j = i;
            hold = prefix[i] -(( i+1)*(i+1) )+ (i+1);
        }
        ans = max(ans,prefix[j] + (i - j + 1)*(i+j+2) + prefix[n] - prefix[i+1]);
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
