#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(v[i]%2==0&&k>0){
            k--;
            v[i]++;
        }
    }
    long long ans = 0;
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++)
    {
        long long hold = v[i];
        long long p = 2;

        while(hold>0){
            if(hold%2==1){
                ans++;
            }
            else if(k>=p){
                ans++;
                k-=p;
            }
            p*=2;
            hold/=2;
        }
    }

    cout<<ans<<" "<<k<<endl;
    
    
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
