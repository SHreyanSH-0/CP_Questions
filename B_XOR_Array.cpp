#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{

    int n,l=0,r=0;
    cin>>n>>l>>r;
    vector<int> arr(n - (r-l+1) + 1,1);
    
    for(int i=1;i<=20;i++){
        int hold = 1<<i;
        for(int j=hold;j<=n -(r-l+1) ;j+=hold){
            arr[j] = ((arr[j]<<1)|1);
        }
    }    
    
    vector<int> v(r-l+1, 3);

    for(int i = 1;i<=20;i++){
        int hold = 1<<i;
        for(int j=hold-1;j<r-l+1;j+=hold){
            v[j] = ((v[j]<<1)|1);
        }
    }

    v[0] = (1<<26);

    int x = 0;
    for(int i=0;i<v.size()-1;i++){
        x^= v[i];
    }
    v[v.size()-1] = x;

    for (int i = 1; i <l; i++)
    {
        cout<<arr[i]<<" ";
    }
    for (int i = 0; i <v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    for (int i = l; i <arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    cout<<endl;
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
