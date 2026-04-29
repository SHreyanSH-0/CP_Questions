#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void YourName()
{
    int n;
    string s,t;
    cin>>n>>s>>t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    if (s == t) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    while(test--)
    {
        YourName();
    }
    return 0;
}
