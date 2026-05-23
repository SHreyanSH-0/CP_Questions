#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
vector<int> x = {1,-1,0,0};
vector<int> y = {0,0,-1,1};
char wall = '#';
char empt = '.';
char good = 'G';
char bad = 'B';
bool rec(vector<string>&v,vector<vector<int>>&vis,int i,int j, int n, int m){
    if(i==n-1&&j==m-1) return vis[i][j]=true;
    if(vis[i][j]!=-1) return vis[i][j];
    vis[i][j] = 0;
    for(int it = 0;it<4;it++){
        int r = i + x[it];
        int c = j + y[it];

        if(r>=0&&c>=0&&r<n&&c<m){
            if(v[r][c]==empt){
                v[r][c] = wall;
            }
            else if(v[r][c]==good){
                vis[i][j] = 1;
                return true;
                break;
            }
            else if(v[r][c] == bad){
                vis[i][j] = rec(v,vis,r,c,n,m);
            }
        }
    }
    return vis[i][j];
}
void rec2(vector<string>&v,vector<vector<int>>&vis,int i,int j, int n, int m){
    if(vis[i][j]!=-1) return;
    vis[i][j] = 1;
    for(int it = 0;it<4;it++){
        int r = i + x[it];
        int c = j + y[it];

        if(r>=0&&c>=0&&r<n&&c<m){
            if(v[r][c]==empt||v[r][c]==good){
                rec2(v,vis,r,c,n,m);
            }
        }
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    vector<vector<int>> vis(n,vector<int>(m,-1));
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }  

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(v[i][j]==bad){
                if(rec(v,vis,i,j,n,m)){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
    }
    
    if(v[n-1][m-1] != wall)
    rec2(v,vis,n-1,m-1,n,m);


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(v[i][j]==bad&&vis[i][j]==1){
                cout<<"No"<<endl;
                return;
            }
            if(v[i][j]==good&&vis[i][j]!=1){
                cout<<"No"<<endl;
                return;
            }
        }
    }

    cout<<"Yes"<<endl;

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
