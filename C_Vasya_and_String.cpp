#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
map<int,int> m;
int rec(string &s, int i, int prev,int k){
    if(i>=s.size()) return 0;
    int hold = ((((i<<20)|k)<<2)|(prev+1));
    if(m.find(hold)!=m.end()) return m[hold];
    int change = 0, notChange = 0;
    int notStart = 0;
    if(prev==-1){
        change = 1 + rec(s,i+1,!(s[i]-'a'),k-1);
        notChange = 1 + rec(s,i+1,(s[i]-'a'),k);
        notStart = rec(s,i+1,-1,k);
        return m[hold] = max(change,max(notChange,notStart));
    }
    else{
        if(s[i]-'a'==prev){
            return m[hold]= 1 + rec(s,i+1,prev,k);
        }
        else{
            if(k>0){
                return m[hold]=1 + rec(s,i+1,prev,k-1);
            }
            else return  m[hold]= 0;
        }
    }
}

void solve()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    cout<< rec(s,0,-1,k);
}
signed main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
