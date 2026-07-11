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
    
    sort(v.rbegin(),v.rend());

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int x = v[i];
            int y = v[j];
            vector<int> hold = {x,y};
            
            for(int k=2;k<n;k++){
                int a = hold[k-1];
                int b = hold[k-2];

                if(a==0) break;

                hold.push_back(b%a);
            }

            if(hold == v) {
                cout<<x<<" "<<y<<endl;
                return;
            }
        }
        
    }
    
    cout<<"-1"<<endl;
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
