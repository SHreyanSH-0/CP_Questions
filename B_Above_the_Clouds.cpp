#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    unordered_map<char,int> map;
    for(int i=0;i<n-1;i++){
        if(map.find(s[i])!=map.end()){
            cout<<"Yes\n";
            return;
        }
        map[s[i]]++;
    }
    map.clear();
    for(int i=n-1;i>0;i--){
        if(map.find(s[i])!=map.end()){
            cout<<"Yes\n";
            return;
        }
        map[s[i]]++;
    }
    cout<<"No\n";
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
