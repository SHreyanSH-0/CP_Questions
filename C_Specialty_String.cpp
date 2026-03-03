#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int ct = 0;
    for (int i = 0; i < n-1; i++)
    {
        if(s[i]==s[i+1]&&s[i]!='*'){
            int a = i;
            int b = i+1;
            while(a>=0&&b<n){
                if(s[a]=='*') {a--; continue;}
                if(s[b] == '*') {b++; continue;}
                if(s[a]==s[b]){
                    s[a] = s[b] = '*';
                    a--;
                    b++;
                }
                else break;
            }
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        if(s[i]!='*'){
            cout<<"NO"<<endl;
            return;
        }
    }
    
    cout<<"YES"<<endl;
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
