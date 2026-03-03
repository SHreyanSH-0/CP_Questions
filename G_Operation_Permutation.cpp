#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int power(int a,int b){
    int ans = 1;
    while(b>0){
        if(b%2==1) ans = (ans * a)%mod;
        a = (a*a)%mod;
        b/=2;
    } 
    return (ans*a)%mod;
}

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> add, mul;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        int hold;
        cin>>hold;
        if(c=='+') add.push_back(hold);
        else if(c=='-') add.push_back(-hold);
        else if(c=='x') mul.push_back(hold);
        else mul.push_back(power(hold,mod-2));
    }


    
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
