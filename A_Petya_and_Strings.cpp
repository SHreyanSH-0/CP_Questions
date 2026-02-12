#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    string s1 , s2;
    cin>>s1>>s2;
    if(s1==s2) cout<<0<<endl;
    else {
        int ans = 0;
        for (int i = 0; i < s1.size(); i++)
        {

            if(tolower(s1[i])>tolower(s2[i])){
                ans = 1;
                break;
            }
            else if(tolower(s1[i])<tolower(s2[i])){
                ans = -1;
                break;
            }
        }
        cout<<ans<<endl;
        
    }
}
int main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
