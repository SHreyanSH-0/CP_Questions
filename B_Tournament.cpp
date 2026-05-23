#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

bool check(int a,int b,vector<vector<int>> &v){
    vector<int> aDef = v[a];
    vector<int> bLost;
    int n = v.size() - 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==b){
                bLost.push_back(i);
                break;
            }
        }
    }

    for(int i=0;i<aDef.size();i++){
        for(int j=0;j<bLost.size();j++){
            if(aDef[i]==bLost[j]){
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int n;
    cin>>n;

    vector<vector<int>> v(n+1);
    set<pair<int,int>> s;
    for(int i=0;i<(n*(n-1))/2 - 1;i++){
        int w,l;
        cin>>w>>l;
        v[w].push_back(l);
        s.insert({w,l});
    }
    int a = -1,b= -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if(s.find({i,j})==s.end()&&s.find({j,i})==s.end()){
                a = i;
                b = j;
                break;
            }
        }   
    }

    if(check(a,b,v)) cout<<a<<" "<<b<<endl;
    else cout<<b<<" "<<a<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
