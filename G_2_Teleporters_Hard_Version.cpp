#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,c;
    cin>>n>>c;
    vector<int> v(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
        
    vector<int> hold,sum(n);
    for(int i=0;i<n;i++){
        hold.push_back(min(v[i]+i+1,v[i]+n-i));
    }
    sort(hold.begin(),hold.end());
    
    sum[0] = hold[0];
    for(int i=1;i<n;i++){
        sum[i] = hold[i] + sum[i-1];
    }
    int ans1 = 0;
    for (int i = 0; i < n; i++)
    {   
        ans = 0;
        int h = c;
        if(v[i]+i+1<=c){
            h -= (v[i] + i + 1);
            int find = (min(v[i]+i+1,v[i]+n-i));
            int ind = lower_bound(hold.begin(),hold.end(),find) - hold.begin();
            int end = ind-1;
            int start = ind+1;


            // cout<<ind<<" ";



            if(end>=0){
                int low = 0, high = end;
                while(low<=high){
                    int mid = (low+high)/2;
                    if(sum[mid]<=h){
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
                ans += low;
                if(low>0)
                h -= sum[low-1];

                // cout<<low<<" ";
            }
            // else cout<<"bj"<<" ";
            
            if(start<n){
                int low = start, high = n-1;
                while(low<=high){
                    int mid = (low+high)/2;
                    if(sum[mid] - sum[ind]<=h){
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
                ans += low - start;
                // cout<<low<<"-"<<start<<" ";
            }
            // else cout<<"bj"<<" ";

            ans1 = max(ans+1,ans1);

            // cout<<ans1<<endl;
        }
        else continue;
    }
    cout<<ans1<<endl;
        
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
