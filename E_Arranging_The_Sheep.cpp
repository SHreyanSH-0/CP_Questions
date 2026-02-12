#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
long long check(string &nums, long long k, long long end, long long start)
{
    long long ans1 = 0;
    long long raone = 1, laone = k - 1;
    long long e = end;
    for (long long i = start + 1; i <= end; i++)
    {
        if (nums[i] == '.')
        {

            if (raone < laone)
            {
                ans1 += (i - start++);
            }
            else
            {
                ans1 += ((e--) - i);
            }
        }
        else
        {
            raone++;
            laone--;
        }
    }
    return ans1;
}

void solve()
{
    long long n;
    cin >> n;
    string nums;
    cin >> nums;
    long long k = 0;
    for (long long i = 0; i < n; i++)
    {
        if (nums[i] == '*')
            k++;
    }
    long long one = 0;
    long long j = 0;
    long long start = 0, end = nums.size();
    for (long long i = 0; i < nums.size(); i++)
    {
        if (nums[i] == '*')
        {
            one++;
        }

        if (one == k)
        {
            while (j<n&&nums[j] != '*')
            {
                j++;
            }
            if (end - start > i - j)
            {
                end = i;
                start = j;
            }
            j++;
            one--;
        }
    }
    cout<< check(nums, k, end, start)<<endl;
}
int main()
{

    ll test = 1;
    cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
