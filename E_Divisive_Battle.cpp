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
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    bool check = false;
    for (int i = 0; i < n-1; i++)
    {
        if(v[i]>v[i+1]) check = true;
    }

    if(check){
        for (int i = 0; i < n; i++)
        {
            int hold = v[i];
            int l = sqrt(hold);
            set<int> s;
            for (int j = 2; j <= l; j++)
            {
                if(s.size()>=2) break;
                while(hold%j==0){
                    s.insert(j);
                    hold/=j;
                }
            }
            if(hold>1) s.insert(hold);
            if(s.size()>=2){
                cout<<"Alice"<<endl;
                return;
            }
            else{
                v[i] = *s.begin();
            }
        }
        check = false;
        for (int i = 0; i < n-1; i++)
        {
            if(v[i]>v[i+1]) check = true;
        }
        if(check) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;

    }
    else{
        cout<<"Bob"<<endl;
    }
    
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
