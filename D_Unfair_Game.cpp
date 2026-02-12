#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
vector<long long> f(int n) {
    vector<long long> res;
    long long cur = 1;   // nC0 = 1
    res.push_back(cur);

    for (int i = 1; i <= n; i++) {
        cur = cur * (n - i + 1) / i;   // nCi from nC(i-1)
        res.push_back(cur);
    }
    return res;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    int a = __builtin_popcount(n) + log2(n);
    int h = log2(n);
    if(a<=k) n--;
    if(k>=1) n--;
    for (int d = 2; d <=h; d++)
    {   
        int hold = k - d;
        if(hold==0){ n--; continue;}
        else if(hold<0) continue;
        vector<long long> v = f(d-1);

        for (int i = 0; i<d && i<=hold; i++)
        {
            if(n<0) break;
            n-= v[i];
        }
    }

    if(n<0) cout<<0<<endl;
    else
    cout<<n<<endl;
    
}
signed main() {
    
    
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
