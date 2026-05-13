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
    vector<int> v(n), spf = smallestPrimeFactor(1e7);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> a(n,-1),b(n,-1);
    for (int i = 0; i < n; i++)
    {
        int hold = v[i];
        vector<int> prime;
        while(hold>1){
            prime.push_back(spf[hold]);
            int p = spf[hold];
            while(hold%p==0)
            hold/=p;
        }

        if(prime.size()>=2){
            a[i] = (prime[0]);
            int prod = 1;
            for (int j = 1; j < prime.size(); j++)
            {
                prod*=prime[j];
            }
            b[i] = prod;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<b[i]<<" ";
    }cout<<endl;
    
    
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
