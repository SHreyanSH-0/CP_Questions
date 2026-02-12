#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    double n,s;

    cin>>n>>s;

    vector<vector<double>> v(n,vector<double>(4));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin>>v[i][j];
        }
        
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        double x = v[i][2];
        double y = v[i][3];
        double r1 = (s-y)/(s-x);
        double r2= (-y)/(s-x);
        double r3 = (y)/(x);
        double r4 = (s-y)/(-x);
        double vx = v[i][0];
        double vy = v[i][1];

        double d = vy/vx;
        if(d==r1||d==r2||d==r3||d==r4) ans++;        
    }
    cout<<ans<<endl;
    
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
