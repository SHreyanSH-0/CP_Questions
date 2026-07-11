#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
vector<int> spf;


void fun(){
    int n = 1e6;
    spf = vector<int>(n+1);
    
    for(int i=0;i<=n;i++){
        spf[i] = i;
    }
    for(int i=2;i<=1e6;i++){
        if(spf[i] == i){
            for (int j = i*i; j <= n; j+=i)
            {
                if(spf[j] == j)
                spf[j] = i;
            }
        }
    }

}
void solve()
{
    int n;
    cin>>n;

    int ans = 0;
    set<int> s;
    while(n >1){
        s.insert(spf[n]);
        n /= spf[n];
        ans++;
    }
    cout<<ans + s.size() - 1<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
fun();
    while(test--)
    {
        solve();
    }
    return 0;
}
