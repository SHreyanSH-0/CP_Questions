#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> b(m);
    set<int> s;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        s.insert(a);
    }
    vector<int> map(n + m+1,0);
    vector<bool> vis(n + m +1,false);
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
        maxi = max(maxi,b[i]);
        map[b[i]]++;
    }
    sort(b.begin(),b.end());
    int lcm = 1;
    int onlya = 0;
    int A = 0, B = 0;
    for(auto &it : s){
        for(int i=it;i<=maxi;i+=it){
            if(!vis[i]) A += map[i];
            vis[i] = true;
        }
    }    
    B = b.size() - A;
    bool check = true;
    for(auto&it:s){
        int hold = __gcd(lcm,it);
        if(lcm>maxi) {
            check = false;
            break;
        }
        lcm = (lcm*it)/hold;
    }
    if(check){
        for(int i=0;i<b.size();i++){
            if(b[i]%lcm==0) onlya++;
        }
    }

    int inter = A - onlya;
    int ac = onlya + (inter + 1)/2;
    int bc = B + inter/2;
    if(ac>bc) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
    
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
