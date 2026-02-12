#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n ;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x^=v[i];
    }
    
    if(x==0){
        cout<<1<<endl;
        cout<<1 <<" "<<n<<endl;
    }
    else if(n%2==0){
        cout<<2<<endl;
        cout<<1 <<" "<<n<<endl;
        cout<<1 <<" "<<n<<endl;
    }
    else{
        cout<<4<<endl;
        cout<<1 <<" "<<n<<endl;
        cout<<1 <<" "<<n-1<<endl;
        cout<<n-1 <<" "<<n<<endl;
        cout<<n-1 <<" "<<n<<endl;
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
