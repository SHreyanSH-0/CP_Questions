#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    int ones = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if((v[i]==1)) ones++;
    }

    if(ones>k){
        cout<<1<<endl;
    }
    else{
        sort(v.begin(),v.end());
        unordered_map<int,int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[v[i]]++;
        }
        int ans = 1;
        for (int i = 2; i <= n; i++)
        {
            int l = lower_bound(v.begin(),v.end(),4*i) - v.begin();

            int left = l;

            left -= (mp[i] + mp[2*i] + mp[3*i]);
            if(left<=k){
                ans = i;
            }
        }

        cout<<ans<<endl;
        

    }

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
