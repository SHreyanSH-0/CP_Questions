#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int sum =  v[0];
    int ans = v[0];
    for (int i = 1; i < n; i++)
    {
        if(abs(v[i-1]%2)==abs(v[i]%2)||sum<0){
            sum = v[i];
        }
        else{
            sum+=v[i];
        }

        ans = max(ans,sum);
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
