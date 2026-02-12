#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }   
    
    if(k>=3) cout<<0<<endl;
    else if(k==2){
        sort(v.begin(),v.end());
        ll ans = LLONG_MAX;
        vector<ll> h;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                ll hold = abs(v[i]-v[j]);
                ans = min(ans,hold);

                int low = 0, high = n-1;

                while (low<=high)
                {
                    int mid = (low+high)/2;
                    if(v[mid]>=hold){
                        high = mid-1;
                    }
                    else{
                        low = mid + 1;
                    }
                }
                ans = min(ans,abs(hold-v[low]));
                
                low = 0; 
                high = n-1;
                
                while (low<=high)
                {
                    int mid = (low+high)/2;
                    if(v[mid]<=hold){
                        low = mid + 1;
                    }
                    else{
                        high = mid-1;
                    }
                }
                
                ans = min(ans,abs(hold-v[high]));
            }
        }
        
        cout<<min(ans,v[0])<<endl;
    }
    else{
        sort(v.begin(),v.end());

        ll ans = v[0];

        for (int i = 0; i < n-1; i++)
        {
            ll hold = abs(v[i]-v[i+1]);
            ans = min(ans,hold);
        }

        cout<<ans<<endl;
    }
}

int main(){

    ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}