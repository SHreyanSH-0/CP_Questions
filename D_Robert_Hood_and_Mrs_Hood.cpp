#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,d,k;
    cin>>n>>d>>k;
    vector<int> start(n+1,0),end(n+1,0);
    for (int i = 0; i < k; i++)
    {
        int a,b;
        cin>>a>>b;
        start[a]++;
        end[b]++;
    }    
    int ans1=1, ans2=1;
    int val1 = -1, val2 = INT_MAX;
    int s = 0, e = 0;
    for(int i=1;i<=d;i++){
        s += start[i];
    }
    int prev = 1;
    val1 = val2 = s;
    for (int i = d+1; i<=n; i++,prev++)
    {
        s+=start[i];
        s-=end[prev];
        if(val1<s) {
            val1 = s;
            ans1 = prev+1;
        }
        if(val2>s){
            val2 = s;
            ans2 = prev+1;
        }
    }   
    
    cout<<ans1<<" "<<ans2<<endl;
        
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
