#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007

void getFactors(long long n,unordered_set<int> &s,int x) {
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if(i+1>=x)
            s.insert(i+1);
            if (i != n / i){
                
                if(n/i + 1>=x)
                s.insert(n / i+1); // Add the complementary divisor
            } 
        }
    }
}

void solve()
{
    int n,x;
    
    cin>>n>>x;
    
    int hold = n - x;
    int hold2 = n + x-2;

    int k = max(x,(ll)2);
    
    unordered_set<int> ans;

    if(hold%2==0){
        getFactors(hold/2,ans,x);
    }

    if(hold2%2==0){
        getFactors(hold2/2,ans,x);
    }

    cout<<ans.size()<<endl;
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
