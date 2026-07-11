#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,s;
    cin>>n>>s;

    string a = to_string(n);
    int sum = 0;
    for(int i=0;i<a.size();i++){
        sum += a[i] - '0';
    }

    if(sum <= s){
        cout<<0<<endl;
        return;
    }
    
    int idx = -1;
    sum = 0;
    for(int i=0;i<a.size();i++){
        sum += a[i] - '0';
        if(sum >= s){
            idx = i;
            break;
        }
    }
    

    int d = a.size() - idx;

    int p = pow(10, d);
    sum = 0;

    for(int i = idx;i<a.size();i++){
        sum = sum*10 + a[i] - '0';
    }

    int hold = sum;
    cout<<p - hold<<endl;


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
