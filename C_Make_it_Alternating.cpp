#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

long long factorial(long long n)
{
    long long res = 1;
    for (long long i = 2; i <= n; i++){

        res *= i;
        res%= mod;
    }
    return res;
}

void solve()
{
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            int hold = 1;
            while (i<s.size()-1&&s[i]==s[i+1])
            {
                hold++;
                i++;
            }
            v.push_back(hold);
        }
    }
    if(v.size()>0){
        long long ans = 1, operation = 0;
        for (int i = 0; i < v.size(); i++){
            operation+= v[i]-1;
            ans *= v[i];
            ans%=mod;
        }
        ans = ans*factorial(operation)%mod;
        cout<<operation<<" "<<ans<<endl;
    }
    else cout<<0<<" "<<1<<endl;
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
