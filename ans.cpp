#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    getline(cin,s);
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='_') continue;
        if(s[i]=='&'||s[i]=='*'||s[i]=='#'){
            j = i + 1;
            while (j<s.size()&&(s[j]=='&'||s[j]=='*'||s[j]=='#'||s[j]=='_'||s[j]==' '))
            {
                j++;
            }
            if(j==s.size()) return;
            s[j++] = '_';
            continue;
        }
        cout<<s[i];
    }
    
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
