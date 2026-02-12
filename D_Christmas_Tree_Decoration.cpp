#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 998244353

int fact(int n){
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f = (f*i)%mod;
    }
    return f;
}

int fun(int small, int hold){
    int fact = 1;
    for (int i = hold+1; i <= small; i++)
    {
        fact = (fact * i)%mod;
    }
    return fact;
    
}

void solve()
{
    int n;
    cin>>n;

    vector<int> v(n);
    int a;
    cin>>a;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int m = *max_element(v.begin(),v.end()) -1;
    int hold = a;
    for (int i = 0; i < n; i++)
    {
        int diff = m - v[i];

        if(diff>0){
            if(hold>=diff){
                v[i] = m;
                hold-=diff;
            }
            else{
                cout<<0<<endl;
                return;
            }
        }
    }

    m++;
    int ct = 0;
    
    for (int i = 0; i < n; i++)
    {
        if(v[i]==m) ct++;
    }

    int small = n - ct;
    int big = ct;
    if(hold>=small){
        hold-=small;
        small=0;
        hold = hold%n;
    }
    if(hold>=small){
        hold -= small;
        big = n;
        small = 0;
    }
    
    int ans;
    
    if(small==0){
        ans = fact(n);
    }
    else{
        ans = (fun(small,hold))*fact(hold+big)%mod;
    }

    cout<<ans<<endl;

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
