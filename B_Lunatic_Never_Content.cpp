#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;

    vector<long long> v(n);
    long long m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m = max(m, v[i]);
    }

    long long mod = 0;

    for (int i = 0; i < n / 2; i++)
    {
        long long hold = max(v[i], v[n - i - 1]) - min(v[i], v[n - i - 1]);
        if(mod>0&&hold>0) mod = __gcd(mod,hold);
        else mod = max(mod,hold);
    }
    int i = 0;
    if(mod==0) cout<<0<<endl;
    else{

        for (i = 0; i < n / 2; i++)
        {
            if(v[i]%mod!=v[n-1-i]%mod) break;
        }
        if(i==n/2) cout<<mod<<endl;
        else cout<<1<<endl;
    }

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
