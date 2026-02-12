#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll l1, l2, l3, b1, b2, b3;

    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    if (b1 == b2 && b2 == b3)
    {
        if (b1 == l1 + l2 + l3)
        {
            cout << "YES\n";
            return;
        }
    }

    if (l1 == l2 && l2 == l3)
    {
        if (l1 == b1 + b2 + b3)
        {
            cout << "YES\n";
            return;
        }
    }

    if (b1 == b2 + b3 && b1 == l1 + l2 && l2 == l3)
    {
        cout << "YES\n";
        return;
    }

    if (l1 == l2 + l3 && l1 == b1 + b2 && b2 == b3)
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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
