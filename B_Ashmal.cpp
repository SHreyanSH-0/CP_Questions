#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {   
        string hold;
        cin>>hold;
        v[i] = hold;
    }
    string ans;
    string s1,s2;
    for (int i = 0; i < n; i++)
    {
        s1 = ans + v[i];
        s2 = v[i] + ans;

        bool check = false;

        for (int j = 0; j < s1.size(); j++)
        {
            if(s1[j]<s2[j]) break;
            else if(s1[j]>s2[j]){
                check = true;
                break;
            }
        }

        if(check){
            ans = s2;
        }
        else ans = s1;
        
    }
    cout<<ans<<endl;
    
       
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
