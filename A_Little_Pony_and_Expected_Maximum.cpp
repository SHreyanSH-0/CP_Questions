#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define mod 1000000007
void solve()
{
    double m,n;
    cin>>m>>n;
    double sum = 0;
    double limit = 0.00000001;

    for(double i=1;i<=m-1;i++){
        double hold = i/m;
        int ct = 0;
        double ans = 1;
        while(ct<n&&ans>limit){
            ans = ans * hold;
            ct++;
        }
        sum+=ans;
        // cout<<ans<<endl;
    }

    cout<<fixed<<setprecision(12)<< m-sum;
}
int main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
