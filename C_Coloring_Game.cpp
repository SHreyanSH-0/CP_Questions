#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    long long n;
    cin>>n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++){
        cin>>v[i];
    }

    long long ans = 0;

    for (long long i = 0; i < n-2; i++){
        for (long long j = i+1; j < n-1; j++)
        {
            long long sum = v[i] + v[j];
            long long l = j+1, r = n-1;

            while (l<=r)
            {
                long long mid = (l+r)/2;
                if(v[mid]<sum){
                    l = mid + 1;
                }
                else{
                    r = mid -1;
                }
            }
            
            long long a = r;

            l = j+1;

            while (l<=r)
            {
                long long mid = (l+r)/2;
                if(v[mid]>v[n-1]-sum){
                    r = mid-1;
                }
                else {
                    l = mid+1;
                }
            }
            // cout<<a<<" "<<l<<endl;
            // cout<<i<<" "<<j<<endl;
            if(a>=r)
            ans += a - l + 1;
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