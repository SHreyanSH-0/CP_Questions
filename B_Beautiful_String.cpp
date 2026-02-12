#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    vector<int> ans ;
    int c = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            c++;
            ans.push_back(i);
        }
    }

    cout<<c<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;
    
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
