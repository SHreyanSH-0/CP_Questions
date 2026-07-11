#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> ct(4,0);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    stack<int> ind;
    for(int i=0;i<n-2;i++){
        ct[v[i]]++;
        if(v[1] >= v[2] + v[3]){
            ind.push(i);
        }
    }
    vector<int> pref(n,0);
    if(v[0] == 3) pref[0] = 1;
    for(int i=1;i<n;i++){
        pref[i] = pref[i-1] + (v[i] == 3);
    }
    for(int j=n-2;j>=1;j--){
        while(!ind.empty() && ind.top() >= j) ind.pop();
        if(v[j]==3) continue;
        if(!ind.empty() && pref[j] - pref[ind.top()] <= (j - ind.top())/2){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
