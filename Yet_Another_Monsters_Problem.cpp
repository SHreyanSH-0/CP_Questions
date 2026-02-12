#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
     int n;
    cin>>n;
    vector<int> v(n);
    map<int,int,greater<int>> map;
    int m = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        map[v[i]]++;
        m = min(m,v[i]);
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
