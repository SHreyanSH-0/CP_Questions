#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,s;
    cin>>n>>s;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int ans = 0;
    if(s<=a[0]){
        ans = a[n-1] - s;
    }
    else if(s>=a[n-1]){
        ans = s - a[0];
    }
    else{
        
        int p1 = s-a[0]+a[n-1] - a[0];
        int p2 = a[n-1] - s + a[n-1] - a[0];
        ans = min(p1,p2);
        
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
