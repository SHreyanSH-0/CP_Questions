#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define ia(a, n) for(int i=0; i<n;i++) cin >> a[i];
void solve()
{
    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    vector<bool> vis(3001,false);
    ia(v,n);
    for (int i = 0; i < n; i++)
    {
        vis[v[i]] = true;
    }

    for(int i=0;i<n;i++){
        for(int j=2;j<=k;j++){
            vis[v[i]/j] = true;
        }
    }

    int low = 0, high = 3000;
    int ans = 0;
    while(low<=high){
        int mid = (low + high)/2;
        bool check = false;
        for (int mini = 0; mini <= v[0]; mini++)
        {
            if(!vis[mini]) continue;
            bool c = true; 
            int l = mini*k;
            int r = (mini + mid) * k;
            for (int i = 0; i < n; i++)
            {
                if(mini == 0 && mid == 0){
                    if(v[i] >= k) {
                        c= false;
                        break;
                    }
                }
                else{
                    if(( k < ceil((double)(v[i]+1)/(1+mini + mid)) || (mini!=0 && ceil((double)(v[i]+1)/(1+mini + mid)) == (v[i])/(mini) + 1)  )){
                        // cout<<i<<" "<<mid <<" "<<mini<<endl;
                        c = false;
                        break;
                    }
                }
            }
            if(c) {
                check = true;
                break;
            }
        }

        // cout<<mid<<","<<check<<" ";
        if(check) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
        
    }
    // cout<<endl;
    cout<<ans<<endl;
}
int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
