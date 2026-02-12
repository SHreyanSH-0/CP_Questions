#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        int hold;
        cin>>hold;
        s.insert(hold);
    }
    
    for(auto i: s){
        v.push_back(i);
    }

    sort(v.begin(),v.end());
    n = v.size();
    for (int i = 0; i < n; i++)
    {
        
    }
    
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
