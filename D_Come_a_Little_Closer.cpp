#include <bits/stdc++.h>
using namespace std;

long long area(vector<vector<long long>> v)
{
    long long ans;
    long long x1, x2, y1, y2;
    x1 = y1 = INT_MAX;
    x2 = y2 = INT_MIN;
    int check;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][0] == -1 || v[i][1] == -1)
        {
            continue;
        }
        if (x1 > v[i][0])
        {
            x1 = v[i][0];
        }
        if (x2 < v[i][0])
        {
            x2 = v[i][0];
        }
        if (y1 > v[i][1])
        {
            y1 = v[i][1];
        }
        if (y2 < v[i][1])
        {
            y2 = v[i][1];
        }
    }
    ans = (x2-x1+1)*(y2-y1+1);
    if(ans==v.size()-1){
        ans+=min((y2-y1+1),x2-x1+1);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;
        vector<vector<long long>> v;

        for (int i = 0; i < n; i++)
        {
            int h1, h2;
            cin >> h1 >> h2;
            v.push_back({h1,h2});

        }

        

        if (n == 1)
            cout << 1 << endl;
        else
        {
            long long ans = 1e18;

            long long x1, x2, y1, y2;
            x1 = y1 = INT_MAX;
            x2 = y2 = INT_MIN;
            int i1, i2, i3, i4;
            for (int i = 0; i < n; i++)
            {
                if (x1 > v[i][0])
                {
                    i1 = i;
                    x1 = v[i][0];
                }
                if (x2 < v[i][0])
                {
                    i2 = i;
                    x2 = v[i][0];
                }
                if (y1 > v[i][1])
                {
                    i3 = i;
                    y1 = v[i][1];
                }
                if (y2 < v[i][1])
                {
                    i4 = i;
                    y2 = v[i][1];
                }
            }
           
            long long hold = v[i1][0];
            v[i1][0] = -1;
            ans = min(ans, area(v));
            v[i1][0] = hold;

            hold = v[i2][0];
            v[i2][0] = -1;
            ans = min(ans, area(v));
            v[i2][0] = hold;

            hold = v[i3][1];
            v[i3][1] = -1;
            ans = min(ans, area(v));
            v[i3][1] = hold;

            hold = v[i4][1];
            v[i4][1] = -1;
            ans = min(ans, area(v));
            v[i4][1] = hold;

            cout << ans << endl;
        }
    }
}