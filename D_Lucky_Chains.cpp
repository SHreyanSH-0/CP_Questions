#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

const int N = 10000000;
int spf[N + 1];

void solve()
{
    int x,y;
    cin>>x>>y;
    if(abs(x-y)==1) {
        cout<<-1<<endl;
        return;
    }
    if(__gcd(x,y)!=1){
        cout<<0<<endl;
        return;
    }
    
    int ans = INT_MAX;

    int diff = abs(x-y);

    vector<int> pf;

    while(diff>1){
        int hold = spf[diff];
        ans = min(ans,(hold - x%hold));
        diff/=hold;
    }
    cout<<ans<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;

    for (int i = 1; i <= N; i++) spf[i] = i;

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    while(test--)
    {
        solve();
    }
    return 0;
}
