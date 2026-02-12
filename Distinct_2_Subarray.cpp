#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    int c = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int hold = 0;
        cin>>hold;
        v[i] = hold;
        if(i>0&&v[i]==v[i-1]) c++;
    }
    if(c==n-1) {cout<<-1<<endl;return;}
    for (int i = 0; i < n; i++)
    {
        if(v[i]!=v[i+1]) {
            cout<<2<<endl;
            return;
        }
    }

    
    cout<<-1<<endl;
    
}
int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
