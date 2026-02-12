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

    bool ans = true;

    int n2 = (2*v[0] - v[1])/(n+1);
    int n1 = v[0] -n*n2;
    
    if(n1<0||n2<0) ans = false;

    for (int i = 0; i < n; i++)
    {
        if(v[i] - n1*(i+1) - n2*(n-i) != 0){
            ans = false;
            break;
        }
    }
    

    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
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
