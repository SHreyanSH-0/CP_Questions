#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n, x;

    cin>>n>>x;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    sort(v.begin(),v.end());
    int num =1;
    int ans = 0;
    for (int i = n-1; i>=0; i--)
    {
        if(v[i]*num>=x){
            ans++;
            num=1;
        }
        else{
            num++;
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
