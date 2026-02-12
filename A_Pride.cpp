#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int rec(vector<int> &v, int i, int ones, vector<vector<int>> &dp, int op)
{
    if (i >= v.size() - 1)
        return 1e5;

    int g = __gcd(v[i], v[i + 1]);

    if (g == 1)
    {
        int ans = ones, prev = -1;
        if (v[i] == 1 && v[i + 1] == 1)
        {
            ans += i;
            prev = i + 1;
            for (int j = i + 2; j < v.size(); j++)
            {
                if (v[j] == 1)
                {
                    ans += j - prev - 1;
                    prev = j;
                }
            }
            if (v[v.size() - 1] != -1)
            {
                ans += v.size() - prev - 1;
            }
        }
        else if (v[i] == 1)
        {

            ans += i;
            prev = i;
            for (int j = i + 1; j < v.size(); j++)
            {
                if (v[j] == 1)
                {
                    ans += j - prev - 1;
                    prev = j;
                }
            }
            if (v[v.size() - 1] != -1)
            {
                ans += v.size() - prev - 1;
            }
        }
        else if (v[i + 1] == 1)
        {
            ans += i + 1;
            prev = i + 1;
            for (int j = i + 2; j < v.size(); j++)
            {
                if (v[j] == 1)
                {
                    ans += j - prev - 1;
                    prev = j;
                }
            }
            if (v[v.size() - 1] != -1)
            {
                ans += v.size() - prev - 1;
            }
        }
        else
        {
            ans += i + 2;
            prev = i + 1;
            for (int j = i + 2; j < v.size(); j++)
            {
                if (v[j] == 1)
                {
                    ans += j - prev - 1;
                    prev = j;
                }
            }
            if (v[v.size() - 1] != -1)
            {
                ans += v.size() - prev - 1;
            }
        }
        return ans;
    }
    else
    {
        if (v[i] == g && v[i + 1] == g)
        {
            return dp[i][op] = rec(v, i + 1, ones, dp, 0);
        }
        else if (v[i] == g)
        {
            int hold = v[i + 1];
            v[i + 1] = g;
            int a = rec(v, i + 1, ones + 1, dp, 1);
            v[i + 1] = hold;
            int b = rec(v, i + 1, ones, dp, 0);
            return dp[i][op] = min(a, b);
        }
        else if (v[i + 1] == g)
        {
            return dp[i][op] = rec(v, i + 1, ones, dp, 0);
        }
        else
        {
            int hold = v[i + 1];
            v[i + 1] = g;
            int a = rec(v, i + 1, ones + 1, dp, 1);
            v[i + 1] = hold;
            int b = rec(v, i + 1, ones, dp, 0);
            return dp[i][op] = min(a, b);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(2, -1));
    int g;
    int ones = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        // if (i > 0)
        // {
        //     g = __gcd(g, v[i]);
        // }
        // else
        //     g = v[i];

        // if (v[i] == 1)
        //     ones++;
    }

    // if (g == 1)
    // {
    //     cout << rec(v, 0, 0, dp,0);
    // }
    // else
    // {
    //     cout << -1 << endl;
    // }

    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        int g = v[i];
        int j;
        for (j = i; j < n; j++)
        {
            g = __gcd(g, v[j]);
            if (g == 1)
            {
                break;
            }
        }
        if (g != 1)
        {
            break;
        }
        int prev = j, hold = 2 * j - i;
        
        for (int k = j+1; k < n; k++)
        {
            if(v[k]==1){
                hold += k-prev-1;
                prev = k;
            }
        }

        if(v[v.size()-1]!=1){
            hold += v.size()-prev-1;
        }
        

        if (ans == -1)
            ans = hold;
        else
            ans = min(ans, hold);
    }

    cout << ans << endl;
}
int main()
{

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
