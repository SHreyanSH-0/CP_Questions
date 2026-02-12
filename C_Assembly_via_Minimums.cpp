#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    long long n;
    cin>>n;
    int vsize = (n*(n-1))/2;
    vector<long long> v(vsize);
    for (int i = 0; i < vsize; i++)
    {
        cin>>v[i];
    }

    sort(v.begin(),v.end());
    int a = 0;
    for(int i=0;i<vsize;i+=n-a){
        cout<<v[i]<<" ";
        a++;
    }
    cout<<v[vsize-1];
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
