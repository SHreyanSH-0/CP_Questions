#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }

        sort(v.begin(), v.end());

        int low = 0, high = n - 1;
        int ans = 0;
        int c1 = 0, c2 = 0;
        if ((v[low] + v[high]) % 2 == 0)
        {
            ans = 0;
        }
        else
        {
            for (int j = 1; v[j] % 2 == v[low] % 2; j++)
            {
                c1++;
            }
            for (int j = n - 2; v[j] % 2 == v[high] % 2; j--)
            {
                c2++;
            }
            

            ans = min(c1 + 1, c2 + 1);
        }

        cout << ans << endl;
    }
}