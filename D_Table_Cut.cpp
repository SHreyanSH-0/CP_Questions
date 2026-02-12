#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    int one = 0;
    vector<vector<int>> v(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>v[i][j];
            if(v[i][j]==1) one++;   
        }
    }
    int n1 = 0, n2 = 0;
    int i = 0, j = 0;
    string ans;
    vector<vector<int>> row(n,vector<int>(m,0)), col(n,vector<int>(m,0));
    for (int i = 0; i < n; i++)
    {
        for(int j=m-1;j>=0;j--){
            if(j==m-1) row[i][j] = v[i][j];
            else row[i][j] = v[i][j] + row[i][j+1];
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for(int j=n-1;j>=0;j--){
            if(j==n-1) col[j][i] = v[j][i];
            else col[j][i] = v[j][i] + col[j+1][i];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for(int j=0;j<m;j++){
    //         cout<<row[i][j]<<" ";
    //     }cout<<endl;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for(int j=0;j<m;j++){
    //         cout<<col[i][j]<<" ";
    //     }cout<<endl;
    // }
    
    while(i<n||j<m){
        int ct1 = 0, ct2 = 0;
        // for(int a = i;a<n&&j<m;a++) {
        //     if(v[a][j] == 1) ct1++;
        // }
        if(i<n&&j<m){
            ct1 = col[i][j];
            ct2 = row[i][j];
        }
        // cout<<col[i][j]<<endl;
        // for(int a = j;a<m&&i<n;a++) {
        //     if(v[i][a] == 1) ct2++;
        // }
        if(n2 + ct2<=(one+1)/2&&i<n) {
            n2 += ct2;
            ans.push_back('D');
            i++;
        }
        else if(n1 + ct1 <= (one+1)/2&&j<m){
            n1+= ct1;
            ans.push_back('R');
            j++;
        }
    }
    cout<<n1*n2<<endl;
    cout<<ans<<endl;

}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
