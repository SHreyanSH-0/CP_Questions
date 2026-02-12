#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    int count = 0;
    vector<int> v(n);
    for (int i = 1; i <= n; i++)
    {
        int hold;
        cin >> hold;
        v[i-1] = hold;
        if(hold==i) count++;
    }
    unordered_map<long long ,long long> map;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        map[v[i-1]-i]++;
    }

    for(auto i:map){
        ans += (i.second*(i.second-1))/2;
    }

    cout<<ans<<endl;
    
    
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
