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
    int ans = 0;
    int two = 0;
    set<int> hold;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(v[i]==2){
            two++;
        } 
        hold.insert(v[i]);
        s.insert(i);
    }

    sort(v.begin(),v.end());

    int low = 1, high = n;

    while(low<=high){
        int mid = (low+high)/2;
        multiset<int> ms;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            ms.insert(v[i]);
        }
        for (int i = 0; i < mid; i++)
        {
            s.insert(i);
        }
        vector<int> err;
        for(auto&it:s){
            auto it2 = ms.find(it);
            if(it2!=ms.end()){
                ms.erase(it2);
                err.push_back(it);
            }
        }

        for (int i = 0; i < err.size(); i++)
        {
            s.erase(err[i]);
        }

        for(auto&it:ms){
            int hold = ceil((double)it/2) - 1;
            if(!s.empty()&&hold>=*(s.begin())){
                s.erase(s.begin());
            }
        }
        if(s.empty()){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    cout<<ans<<endl;
    return;
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
