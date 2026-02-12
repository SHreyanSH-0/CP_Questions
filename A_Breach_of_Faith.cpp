#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;

    vector<int> v(2*n);

    
    for(int i=0;i<2*n;i++){
        cin>>v[i];
    }
    
    sort(v.begin(),v.end());
    
    cout<<v[2*n-1]<<" ";

    int hold = 0, m = 1;
    for (int i = 0; i < 2*n-1; i++)
    {
        hold += m*v[i];
        m*=-1;
    }

    cout<<v[2*n-1] + hold<<" ";

    for (int i = 0; i < 2*n-1; i++)
    {
        cout<<v[i]<<" ";
    }
    
    cout<<endl;
        

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
