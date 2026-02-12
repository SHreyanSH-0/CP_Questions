#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int m = v[0];
    int ans = 0;

    for(int i=0;i<n;i++){
        if(i%2==1){
            v[i] = max(v[i],m);
        }
        m = max(m,v[i]);
   }

   for (int i = 1; i < n; i+=2)
   {
       if(v[i-1]>=v[i]){
           ans+=v[i-1] - v[i] + 1;
           v[i-1] = v[i] -1;
        }
        if(i+1<n){
            if(v[i+1]>=v[i]){
                ans+=v[i+1] - v[i] + 1;
            }
            v[i+1] = v[i] -1;
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
