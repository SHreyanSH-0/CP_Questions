#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    int ans = 0;
    while (s.size()>1)
    {
        while (s.size()>1&&s[s.size()-1]=='0')
        {
            ans++;
            s.pop_back();
        }

        if(s.size()>1&&s[s.size()-1]=='1'){
            ans++;
            int i = s.size()-2;
            while (s.size()>0&&s[s.size()-1]!='0')
            {
                ans++;
                s.pop_back();
            }
            if(s.size()>1){
                s[s.size()-1] = '1';
            }
            
        }
    }

    cout<<ans<<endl;
    
    
}
int main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
