#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int ans = 0;
long long rec(string &s, string &hold, int i, int k, vector<long long> &pow,vector<long long>&dp)
{
    ans++;
    if (hold.size() == 3)
    {
        if ((hold[0] == 'a' || hold[0] == '?') && (hold[1] == 'b' || hold[1] == '?') && (hold[2] == 'c' || hold[2] == '?'))
            return pow[k];
        else
            return 0;
    }
    else if (i >= s.size()) return 0;

    long long a = 0;

    hold += s[i];

    if (s[i] == '?')
        a = rec(s, hold, i + 1, k - 1, pow,dp);
    else
        a = rec(s, hold, i + 1, k, pow,dp);

    hold.pop_back();

    long long b = rec(s, hold, i + 1, k, pow,dp);

    return (a % mod + b % mod) % mod;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int k = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')
            k++;
    }
    vector<long long> pow(k + 1), dp(s.size(),-1);
    
    pow[0] = 1;
    for (int i = 1; i <= k; i++){
        pow[i] = (pow[i - 1] * 3) % mod;
    }
    string hold;
    cout << rec(s, hold, 0, k, pow,dp) % mod << endl;
    // cout<<ans;
}
int main()
{

    ll test = 1;
    while (test--)
    {
        solve();
    }
    return 0;
}
