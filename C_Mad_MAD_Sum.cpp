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
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        ans += v[i];
    }
    map<int,int> map, map2;
    vector<int> p(n,0);
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        map[v[i]]++;
        if(map[v[i]]>1){
            num = max(num,v[i]);
        }
        p[i] = num;
        map2[num]++;
    }
    int hold = 0;

    for (int i = 0; i < n; i++)
    {
        if(p[i]==0) continue;
        if(map2[p[i]]==1){
            ans += p[i];
            p[i] = p[i-1];
            ans -= p[i-1];
        }
    }
    
    for (int i = n-1; i >=0; i--)
    {
        int val = p[i];
        int j = i;
        int ct = 1;
        while(i>0&&p[i] == p[i-1]){
            i--;
            ct++;
        }
        if(ct>1){
            ans += abs(n-1 - j)*(ct*val);
        }
        else{
            hold = 0;
        }
        ans += ((ct*(ct+1))/2)*val;
    }
    
    
    cout<<ans<<endl;
    
    
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
