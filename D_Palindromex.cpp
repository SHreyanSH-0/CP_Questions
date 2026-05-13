#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int mex(set<int>&s){
    int ct=0;
    for(auto&it:s){
        if(it==ct) ct++;
    }
    return ct;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(2*n);
    for (int i = 0; i < 2*n; i++)
    {
        cin>>v[i];
    }
    int z1 = -1, z2 = -1;
    for (int i = 0; i < 2*n; i++)
    {
        if(v[i]==0){
            if(z1==-1) z1=i;
            else z2 = i;
        }
    }

    int ans = 0;
    int l = z1 , r = z2;
    bool check = true;
    while(l<=r){
        if(v[l]==v[r]) {
            l++;
            r--;
        }
        else{
            check = false;
            break;
        } 
    }
    
    if(check){
        l = z1 , r = z2;
        while(l>=0&&r<2*n){
            if(v[l]==v[r]) {
                l--;
                r++;
            }
            else break;
        }

        set<int> s1;
        for (int i = l+1; i < r; i++)
        {
            s1.insert(v[i]);
        }
        ans = max(ans,mex(s1));
    }
    
    l = z1-1;
    r = z1 + 1;
    while(l>=0&&r<2*n){
        if(v[l]==v[r]) {
            l--;
            r++;
        }
        else break;
    }
    set<int> s2;
    for (int i = l+1; i < r; i++)
    {
        s2.insert(v[i]);
    }
    ans = max(ans,mex(s2));
    l = z2-1;
    r = z2 + 1;
    while(l>=0&&r<2*n){
        if(v[l]==v[r]) {
            l--;
            r++;
        }
        else break;
    }
    set<int> s3;
    for (int i = l+1; i < r; i++)
    {
        s3.insert(v[i]);
    }
    ans = max(ans,mex(s3));

    cout<<ans<<endl;
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
