#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

vector<int> sieve(){
    vector<bool> v(1e6 + 1,true);
    v[0] = false;
    v[1] = false;
    for (int i = 2; i*i <= 1e6; i++)
    {
        for (int j = i*i; j <= 1e6; j+=i)
        {
            v[j] = false;
        }
    }

    vector<int> ans;

    for (int i = 0; i <= 1e6; i++)
    {
        if(v[i]){
            ans.push_back(i*i);
        }
    }
    return ans;
    
}

void solve()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    vector<int> v = sieve();
    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(v.begin(),v.end(),nums[i]) - v.begin();
        if(idx<v.size()&&v[idx]==nums[i]){
            cout<<"YES\n";
        }
        else 
        cout<<"NO\n";
    }
    
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
