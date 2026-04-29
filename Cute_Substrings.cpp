#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string hold;
        for (int j = i; j < n; j++)
        {
            hold.push_back(s[j]);
            bool check = true;
            for (int k = 0; k < hold.size(); k+=2)
            {
                if(!(hold[k]=='u'||hold[k]=='o')) check = false;
            }
            for (int k = 1; k < hold.size(); k+=2)
            {
                if(hold[k]!='w') check = false;
            }

            if(check&&(j-i+1)%2==1) ans = max(ans,j - i+1);
            
        }
        
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
