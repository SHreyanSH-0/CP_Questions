#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    vector<int> a;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]!='+'){
            a.push_back(s[i]-'0');
        }
    }

    sort(a.begin(),a.end());

    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i];
        if(i<a.size()-1){
            cout<<'+';
        }
    }cout<<endl;
    
    
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
