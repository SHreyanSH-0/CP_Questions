#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        vector<int> hold(26,0);
        for(int j=0;j<s.size();j++){
            hold[s[j]-'a']++;
        }
        int h = 0;
        for (int j = 0; j < 26; j++)
        {
            if(hold[j]%2==1) {
                h = ((h)|(1<<j));
            }
        }
        map[h]++;
        v[i] = h;
    }
    int ans = 0;
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        int num = v[i];
        ct += (map[num] - 1);
        for (int j = 0; j < 26; j++)
        {
            int h = ((num)^(1<<j));
            ans += map[h];
        }
    }
    cout<<ans/2 + ct/2<<endl;
}

long long ask(int l, int r) {
    if (l > r) return 0;
    cout << "? " << l << " " << r << endl;
    cout.flush();
    long long s;
    cin >> s;
    return s;
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
