#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    vector<int> v;
    int one = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') one++;
    }
    if(k>=one) cout<<"Alice"<<endl;
    else if(k==1) cout<<"Bob"<<endl;
    else if(2*k>n){
        cout<<"Alice"<<endl;
    }
    else if(2*k==n){
        cout<<"Bob"<<endl;
    }
    else cout<<"Bob"<<endl;
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
