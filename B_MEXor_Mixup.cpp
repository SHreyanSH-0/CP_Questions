#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
vector<int> pre;
void solve()
{
    int a,b;
    cin>>a>>b;
    // if(pre[a-1]==b){
    //     cout<<a<<endl;
    // }
    // else if(pre[a-1] == (a^b)){
    //     cout<<a + 2<<endl;
    // }
    // else cout<<a + 1<<endl;


    a = 0;
    for (int i = 0; i <= 30; i++)
    {
        a = a^i;
        cout<<a<<" ";
    }cout<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    int a = 0;
    for (int i = 0; i <= 3e5; i++)
    {
        a = a^i;
        pre.push_back(a);
    }
    

    while(test--)
    {
        solve();
    }
    return 0;
}
