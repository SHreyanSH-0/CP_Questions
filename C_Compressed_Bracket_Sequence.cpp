#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int > v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(i%2==1) continue;
        int startOpen = v[i];
        int restOpen = 0;
        int close = 0;
        int j;
        for (j = i+1; j < n&&startOpen>0; j++)
        {
            if(j%2==0) restOpen += v[j];
            else close += v[j];
            if(restOpen>0){
                if(close<=restOpen) {
                    restOpen -= close;
                    close = 0;
                }
                else{
                    close -= restOpen;
                    restOpen = 0;
                }
                if(restOpen==0) ans++;

            }
            if(restOpen==0&&close>0){
                if(close<=startOpen) {
                    startOpen -= close;
                    ans += close;
                    close = 0;
                }
                else{
                    close -= startOpen;
                    ans += startOpen;
                    startOpen= 0;
                }
            }
        }
        
        if(startOpen==0&&close==0){
            int open = 0;
            
            for(j;j<n;j++){
                if(j%2==0) open+=v[j];
                else close+=v[j];
                
                if(open>=close){
                    open -= close;
                    close = 0;
                }
                else {
                    close-=open;
                    ans++;
                    break;
                }

                if(open ==0) ans++;
            }
        }
    }
    
    cout<<ans<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
