#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;

    vector<long long> vac(31), v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    for (int i = 0; i <= 30; i++)
    {
        int zero = 0;
        for (int j = 0; j < n; j++)
        {
            int hold = 1<<i;
            if((v[j]|(hold) )!= v[j]){
                zero++;
            }
        }
        vac[i] = zero;
    }
    long long ans = 0;
    for (int i = 30; i>=0; i--)
    {
        if(k>=vac[i]){
            ans += 1<<i;
            k-=vac[i];
        }
        else if(vac[i]==0){
            ans += 1<<i;
        }
    }
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
