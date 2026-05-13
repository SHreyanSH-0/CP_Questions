#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> spf(1e7 + 1);
    map<int,int> map;
    vector<int> a(n), b(m);

    for(int i = 0; i <= 1e7; i++) spf[i] = i;

    for(int i = 2; i * i <= 1e7; i++){
        if(spf[i] == i){
            for(int j = i * i; j <= 1e7; j += i){
                if(spf[j] == j)
                    spf[j] = i;
            }
        }

    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a[i] = x;
        while(x > 1){
            
            int p = spf[x];
            map[p]++;
            x /= p;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin>>x;
        b[i] = x;
        while(x > 1){
            int p = spf[x];
            map[p]--;
            x /= p;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int x = a[i];

        while(x > 1){
            int p = spf[x];
            if(map[p]>0){
                map[p]--;
            }
            else{
                a[i]/=p;
            }
            x /= p;
        }

    }
    for (int i = 0; i < m; i++)
    {
        int x = b[i];

        while(x > 1){
            int p = spf[x];
            if(map[p]<0){
                map[p]++;
            }
            else{
                b[i]/=p;
            }
            x /= p;
        }

    }
    cout<<a.size()<<" ";
    cout<<b.size()<<endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout<<b[i]<<" ";
    }cout<<endl;
    
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
