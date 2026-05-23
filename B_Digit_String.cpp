#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    int n= s.size();
    vector<int>v(5,0);
    int ans = 0;
    int last31 = -1;
    int last2 = -1;
    for (int i = 0; i < n; i++)
    {
        v[s[i]-'0']++;
    }

    ans = 1e8;
    int three = 0, one = 0,two = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1' || s[i]=='3'){
            int hold1 = v[4] + v[2] + one + three;
            int hold2 = v[4] + v[2] + two;
            ans = min(ans,min(hold1,hold2));
            if(s[i]=='1') one++;
            else three++;
        }
        else if(s[i]=='2'){
            v[2]--;
            int hold1 = v[4] + v[2] + one + three;
            ans = min(ans,hold1);
            two++;
        }
    }
    if(ans==1e8) ans = v[4];
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
