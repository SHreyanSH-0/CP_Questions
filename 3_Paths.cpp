#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    if(n<3) cout<<-1<<endl;
    else if(n==3){
        cout<<1<<" "<<1<<" "<<1<<endl;
        cout<<0<<" "<<1<<" "<<1<<endl;
        cout<<0<<" "<<1<<" "<<1<<endl;
    }
    else if(n==4){
        cout<<1<<" "<<1<<" "<<1<<" 1"<<endl;
        cout<<1<<" "<<0<<" "<<1<<" 1"<<endl;
        cout<<1<<" "<<0<<" "<<0<<" 1"<<endl;
        cout<<1<<" "<<1<<" "<<1<<" 1"<<endl;
    }
    else{
        vector<vector<int>> v(n,vector<int>(n,0));
        for(int i=0;i<n;i++) v[0][i] = 1;
        for(int i=0;i<n;i++) v[i][n-1] = 1;
        for(int i=0;i<n;i++) v[i][1] = 1;
        for(int i=1;i<n;i++) v[2][i] = 1;
        for(int i=1;i<n;i++) v[n-1][i] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
            
        }
        
    }
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
