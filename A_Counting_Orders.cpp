#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;

    vector<int> a(n),b(n);

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int j = 0;
    long long hold = 0;
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        for(j;j<n;j++){
            if(b[j]<a[i]){
                hold++;
            }
            else{
                break;
            }
        }
        if(hold==0){
            break;
        }
        ans = (ans%mod)*(hold-i);
    }
    if(!hold)
    cout<<0<<endl;
    else
    cout<<ans<<endl;
    
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
