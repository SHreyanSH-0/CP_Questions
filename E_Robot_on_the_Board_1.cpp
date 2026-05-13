#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;

    int up = 0, right = 0, left = 0, down = 0;
    int lm = 0, rm = 0, um = 0, dm = 0;
    int r = 0, c = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='U') up++;
        else if(s[i]=='D') up--;
        else if(s[i]=='L') right--;
        else right++;

        if(up>0) um = max(up,um);
        else dm = min(dm,up);

        if(right>0) rm = max(rm,right);
        else lm = min(lm,right);

        if(abs(lm-rm)<m&&abs(um - dm)<n){
            if(abs(lm)>rm){
                c = abs(lm);
            }
            else{
                c = m - 1 - rm;
            }

            if(um > abs(dm)){
                r = um;
            }
            else r = n - 1 - abs(dm);
        }
        else break;

    }

    cout<<r + 1<<" "<<c + 1<<endl;
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
