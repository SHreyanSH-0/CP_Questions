#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

bool comp(char a, char b){
    cout<<"? "<<a<<" "<<b<<endl;
    cout.flush();
    char c;
    cin>>c;

    if(c=='<') return true;
    else return false;
}

void solve()
{
    int n,q;
    cin>>n>>q;
    string s;
    for (char i = 0; i < n; i++)
    {
        s.push_back('A' + i);
    }
    sort(s.begin(),s.end(),comp);
    cout<<"! "<<s<<endl;
}
signed main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
