#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    long long n;
    cin>>n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];

    long long j;
    long long m = LLONG_MAX, minInd;
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        if(v[i]==v[i+1]){
            j = i;
            while (j+1<n&&v[j]==v[j+1])
            {
                j++;
            }
            long long hold = i*v[i]+(n-j-1)*v[i];
            ans = min(ans,hold);
            i = j;
        }
        
        if(m>v[i]){
            m = v[i];
            minInd = i;
        }
        
    }
    long long hold = minInd*v[minInd]+(n-minInd-1)*v[minInd];
    ans = min(ans,hold);
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
