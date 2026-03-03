#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int fun(string &s){
    int ans = 0;
    for(int i=0;i<s.size();i++){
        ans++;
        while(i+1<s.size()&&s[i] == s[i+1]) i++;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        string hold;
        for (int j = 0; j < n; j++)
        {
            hold.push_back(s[(i + j)%n]);
        }
        ans = max(ans,fun(hold));
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
