#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    if(v[0]==-1&&v[n-1]==-1){
        cout<<0<<endl;
    }
    else if(v[0]==-1){
        v[0] = v[n-1];
        cout<<0<<endl;        
    }
    else if(v[n-1]==-1){
        v[n-1] = v[0];
        cout<<0<<endl;
    }
    else{
        cout<<abs(v[n-1] - v[0])<<endl;
    }

    for (int i = 0; i < n; i++)
    {
        if(v[i]==-1){
            cout<<0<<" ";
        }
        else cout<<v[i]<<" ";
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
