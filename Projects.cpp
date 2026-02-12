#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007

unordered_map<int,int> m;

int rec(vector<vector<int>> &v, int i){
    if(i>=(ll)v.size()) return 0;

    int pick = 0, notPick = 0;

    if(m.find(v[i][0])!=m.end()) return m[v[i][0]];

    int low = 0, high = v.size()-1;

    int val = v[i][1];

    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid][0]>val){
            high = mid-1;
        }
        else low = mid+1;
    }

    pick = v[i][2] + rec(v,low);

    notPick = rec(v,i+1);

    return m[v[i][0]]= max(pick,notPick);
}

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> hold(3);
        cin>>hold[0];
        cin>>hold[1];
        cin>>hold[2];

        v[i] = hold;
    }

    sort(v.begin(),v.end());
    cout<<rec(v,0);
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
