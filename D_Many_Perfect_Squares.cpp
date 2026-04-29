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

    int ans = 1;
    
    for(int i=0;i<n;i++){
        map<int,int> map;
        int a = v[i];
        for (int j = i+1; j < n; j++)
        {
            int b = v[j];
            //(q-p)(q+p) = a[j] - a[i]
            int l = sqrt(v[j] - v[i]);
            int hold = v[j] - v[i];
            for(int k=1;k<=l;k++){
                // 1st
                int q = (k + hold/k)/2;
                int p = (hold/k - k)/2;

                if(q>0 && p>0 && hold == (q-p)*(q+p)){
                    int x = p*p - a;
                    if(x>=0)
                    map[x]++;
                }
                //2nd
                q = (hold/k + k)/2;
                p = (k - hold/k)/2;
    
                if(q>0 && p>0 && hold == (q-p)*(q+p)){
                    int x = p*p - v[i];
                    if(x>=0)
                    map[x]++;
                }
            }
        }
        for(auto&[x,y]:map){
            ans = max(ans,y+1);
        }
    }
    cout<<ans<<endl;
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
