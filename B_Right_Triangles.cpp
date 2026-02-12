#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v2(n,vector<int>(m,-1));
    vector<string> v(n);

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {            
            if(v[j][i]=='*'){
                count++;
            }
        }
        
        for (int j = 0; j < n; j++)
        {            
            if(v[j][i]=='*'){
                v2[j][i] = count-1;
            }
        }
    }

    vector<int> s(n);

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            if(v2[i][j]!=-1) sum+= v2[i][j];
        }
        s[i] = sum;
    }
    
    long long ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(v2[i][j]!=-1)
            ans+= s[i] - v2[i][j];
        }
    }
    cout<<ans<<endl;
    
}
int main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
