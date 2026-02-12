#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> v(m,vector<int>(n));
    int set = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>v[i][j];
            set= max(set,v[i][j]);
        }
    }
    int r,c,total = 0;
    int b = INT_MIN;
    int rMax = 0, cMax = 0;
    for (int i = 0; i < m; i++)
    {
        int ct = 0;
        for (int j = 0; j < n; j++)
        {
            if(v[i][j]==set){
                ct++;
                total++;
            }
            else b = max(b,v[i][j]);
        }
        if(ct>rMax){
            rMax = ct;
            r =  i;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        int ct = 0;
        for (int j = 0; j < m; j++)
        {
            if(v[j][i]==set){
                ct++;
            }
        }
        if(ct>cMax){
            cMax = ct;
            c =  i;
        }
    }

    if(v[r][c]==set&&cMax!=1&&rMax!=1) cMax--;

    if(rMax+cMax>=total){
        cout<<max(set-1,b)<<endl;
    }
    else cout<<set<<endl;
    
    
    
    
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
