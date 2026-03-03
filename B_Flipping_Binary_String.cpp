#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int one = 0, zero =  0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='0') zero++;
        else one++;
    }
    if(zero==n){
        cout<<0<<endl;
        return;
    }
    int z = zero , o = one;
    int ct = 0;
    while(zero!=n&&ct<=z){
        int hold = zero;
        if(ct%2==0){
            zero = one + 1;
            one = hold - 1; 
        }
        else {
            zero = one - 1;
            one = hold + 1; 
        }
        ct++;
    }
    if(zero==n&&ct<=z){
        cout<<ct<<endl;
        for (int i = 0; i < n&&ct>0; i++)
        {
            if(s[i]=='0'){ cout<<i+1<<" "; ct--;}
        }
        cout<<endl;
        return;
    }
    ct = 0;
    zero = z;
    one = o;
    while(zero!=n&&ct<=o){
        int hold = zero;
        if(ct%2==1){
            zero = one + 1;
            one = hold - 1; 
        }
        else {
            zero = one - 1;
            one = hold + 1; 
        }
        ct++;
    }
    if(zero==n&&ct<=o){
        cout<<ct<<endl;
        for (int i = 0; i < n && ct > 0; i++)
        {
            if(s[i]=='1') {cout<<i+1<<" "; ct--;}
        }
        cout<<endl;
        return;
    }
    cout<<-1<<endl;
    
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
