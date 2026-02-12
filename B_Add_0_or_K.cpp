#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(k%2==1){
            if(v[i]%2==1)
                v[i]+= k;
            cout<<v[i]<<" ";
        } 
    }

    if(k%2==1){
        cout<<endl;
        return;
    }

    vector<int> prime = {3, 5, 7, 11, 13, 17, 19, 23, 29};

    for (int i = 0; i < prime.size(); i++)
    {
        if(k%prime[i]==0) continue;
        
        for (int j = 0; j < n; j++)
        {
            if(v[j]%prime[i]!=0){
                
                int ans = 1;
                int req = prime[i] - v[j]%prime[i];
                int hold = k;
                while((hold%prime[i]) !=req){
                    hold = (hold + k);
                    ans++;
                }
                cout<<v[j] + k*ans<<" ";
            }
            else{
                cout<<v[j]<<" ";
            }

            
        }
        break;
        
    }
    cout<<endl;
    
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
