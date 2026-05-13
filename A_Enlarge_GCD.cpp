#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

vector<int> smallestPrimeFactor(int n) {
    vector<int> spf(n + 1);

    for(int i = 0; i <= n; i++) {
        spf[i] = i;
    }

    for(int i = 2; i * i <= n; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j <= n; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n),spf = smallestPrimeFactor(1.5 * 1e7);
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        g = __gcd(g,v[i]);
    }
    sort(v.begin(),v.end());
    int ans = -1;
    map<int,int> count;
    for (int i = 0; i < n; i++)
    {
        int hold = v[i];

        while(hold>1){
            int p = spf[hold];
            int ct = 0;
            while(hold%p==0){
                hold/=p;
                ct++;
                count[pow(p,ct)]++;
            }
        }
    }

    for(auto&it : count){
        if(it.first==g || __gcd(it.first,g)==it.first) continue;

        ans = max(ans,it.second);
    }
    if(ans==-1 || ans == n){
        cout<<-1<<endl;
        return;
    }

    cout<<n - ans<<endl;
    
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
