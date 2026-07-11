#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;

    set<int> s;
    int l = sqrt(n);
    vector<int> fact;
    int h = n;
    for (int i = 2; i <= l; i++)
    {
        if(n%i==0){
            fact.push_back(i);
            while (n%i==0)
            {
                n/=i;
            }
        }
    }
    if(n>1) fact.push_back(n);
    n = h;

    vector<bool> v(n+1,true);
    v[n] = false;
    for (int i = 0; i < fact.size(); i++)
    {
        for (int j = fact[i]; j < n; j+=fact[i])
        {
            v[j] = false;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if(v[i]) s.insert(i);
    }
    
    int m = 1;
    int hold = 1;
    int ct = 0;
    int ansct = 1;
    for(auto&it:s){
        m = (m*it)%n;
        ct++;
        if(m%n==1){
            hold = it;
            ansct = ct;
        }
    }
    cout<<ansct<<endl;
    for(auto&it:s){
        cout<<it<<" ";
        if(it==hold){
            break;
        }
    }
    cout<<endl;
    
    
    
    
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
