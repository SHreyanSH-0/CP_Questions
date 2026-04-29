#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007



void solve()
{
    int n,m,w;
    cin>>n>>m>>w;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int low = 0, high = 1e15;   
    int ans = 0;
    while(low<=high){
        int mid = (low+high)/2;
        int hold = m;
        bool check = true;
        vector<int> diff(n,0);
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += diff[i];
            if(v[i] + sum <mid){
                if(mid-(v[i]+sum)<=hold){
                    int x = (mid - (v[i] + sum));
                    hold -= x;
                    if(i+w<n) diff[i+w] = -x;
                    sum+=x;
                }
                else{
                    check = false;
                    break;
                }
            }
        }

        if(check) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid -1;
    }
    cout<<ans<<endl;
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
