#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    long long x;
    cin >> x;
    long long a = x / 2;
    int ans = 0;
    vector<long long> v = {0, 0, 0};
    while (v[1] < a || v[2] < a)
    {
        ans++;
        v[0] = v[1] * 2 + 1;
        sort(v.begin(), v.end());
    }
    cout << ans + 3 << endl;
}
int main()
{

    ll test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
