#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin>>h[i];
    }

    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        int prev = 0;
        vector<int> hold(n,0);
        hold[i] = 0;
        for (int j = i+1; j < n; j++)
        {
            if(h[j-1] <= prev){
                ans += prev;
            }
            else{
                prev = h[j-1];
                ans+=prev;
            }
            hold[j] = prev;
        }

        int prev2 = 0;

        for (int j = i-1; j >=0; j--)
        {
            if(h[j] <= prev2){
                ans += prev2;
            }
            else{
                prev2 = h[j];
                ans+=prev2;
            }
            hold[j] = prev2;
        }        
        if(h[n-1] < max(prev,prev2) && (prev != prev2)){

            if(i==0){
                ans = ans - prev + h[n-1];   
                hold[n-1] = h[n-1];             
            }
            else if(i==n-1){
                ans = ans - prev2 + h[n-1];
                hold[0] = h[n-1];             
            }
            else{
                if(min(prev,prev2) > h[n-1]){
                    hold[0] = hold[n-1] = min(prev,prev2);           
                }
                else{
                    if(prev>prev2){
                        hold[n-1] = h[n-1];
                    }
                    else{
                        hold[0] = h[n-1];
                    }
                }
            }
        }

        for (int j = 0; j < i-1; j++)
        {
            if(max(hold[j],hold[(j+1)%n]) > h[j] && hold[j]!=hold[(j+1)%n]){
                hold[(j+1)%n] = max(hold[j], h[j]);
            }
        }
        for (int j = n-2; j > i; j--)
        {
            if(max(hold[j],hold[(j+1)%n]) > h[j] && hold[j]!=hold[(j+1)%n]){
                hold[(j)%n] = max(hold[j+1], h[j]);
            }
        }
        
        ans = 0;
        for (int j = 0; j < n; j++)
        {
            ans += hold[j];
        }        
        cout<<ans<<" ";
        
    }cout<<endl;
    
    
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
