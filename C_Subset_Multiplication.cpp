#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    int ans = INT_MAX;
    for (int i = 0; i < n-1; i++)
    {
        if(v[i+1]%v[i]!=0){
            ans = min(ans,__gcd(v[i],v[i+1]));
        }
    }

    if(ans==INT_MAX)
    cout<<1<<endl;
    else 
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
