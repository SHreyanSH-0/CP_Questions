#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> v(n,vector<int>(m,0));

    if(m%k==0){
        int num = 1;

        for (int i = 0; i < n; i++)
        {
            if(i%2==0){

                for (int j = 0; j < m; j++)
                {
                    cout<<num++<<" ";
                    if(num== k+1){
                        num = 1;
                    }
                }
            }
            else{
                cout<<k<<" ";

                for (int j = 0; j < m-1; j++)
                {
                    cout<<num++<<" ";
                    if(num== k+1){
                        num = 1;
                    }
                }

                num = 1;
            }
            
            cout<<endl;
        }
    }
    else{
        int num = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout<<num++<<" ";
                if(num== k+1){
                    num = 1;
                }
            }
            cout<<endl;
            
        }
    }
    
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
