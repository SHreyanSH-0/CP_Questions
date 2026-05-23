#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(n);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        pq.push(v[i]);
    }
    int curr = 0;
    int ans = 0;
    while(curr<m&&!pq.empty()){
        // cout<<curr<<endl;
        int rose = pq.top();
        pq.pop();
        int canPlant = m - curr;
        if(rose<=k){
            if(canPlant<=rose){
                curr = m;
                ans += canPlant;
            }
            else{
                curr += rose+1;
                ans += rose;
            }
        }
        else{
            int hold = canPlant/(k+1);
            int left = canPlant%(k+1);

            if(hold*k<=rose){
                if(hold==0){
                    curr += canPlant;
                    ans += canPlant;
                    rose-=canPlant;
                }
                else{
                    curr += hold*(k+1);
                    ans += hold*k;
                    rose -= hold*k;
                }
            }
            else{
                curr += (rose/(k+1))*(k+1);
                ans += (rose/(k+1))*(k);
                rose -= (rose/(k+1))*(k);
            }
            if(rose>0)
            pq.push(rose);
        }

    }


    cout<<ans<<endl;
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
