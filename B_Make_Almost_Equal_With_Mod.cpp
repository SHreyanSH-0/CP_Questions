#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<long long> v(n);
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(v[i]%2==0) even++;
        else odd++;
    }
    bool check = true;
    if(even>0&&odd>0) cout<<2<<endl;
    else{
                
    }
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
