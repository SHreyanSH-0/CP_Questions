#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] != v[n - i - 1][n - j - 1])
                count++;
        }
    }
    if(n%2==1){
        for(int j=0;j<n/2;j++){
            if(v[n/2][j]!=v[n/2][n-j-1]) count++;
        }
    }
    if (count == k)
        cout << "YES\n";
    else if(n%2==1&&count<k){
        cout<<"YES\n";
    }
    else if(n%2==0&&count<k&&(k-count)%2==0){
        cout<<"YES\n";
    }
    else
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
