#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    sort(v.begin(),v.end());

    vector<pair<int,int>> ans;

    ans.push_back({abs(v[0]),0});
    ans.push_back({x - abs(v[n-1]),x});

    for (int i = 0; i < n-1; i++)
    {
        int hold = (v[i]+v[i+1])/2;

        int hold1 = abs(v[i]-hold);
        int hold2 = abs(v[i+1]-hold);

        ans.push_back({max(hold1,hold2),hold});
    }
    sort(ans.begin(),ans.end());

    for (int i = ans.size()-1, j = 0; i >=0&&j<k; i--)
    {
        cout<<ans[i].second<<" ";
        j++;
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
