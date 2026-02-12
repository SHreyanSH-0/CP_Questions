#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n, o;
    cin>>n>>o;
    for (int i = 0; i < o; i++)
    {
        cout<<1;
    }
    for (int i = o; i < n; i++)
    {
        cout<<0;
    }
    cout<<endl;
    
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
