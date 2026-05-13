#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void solve()
{
    int n,k,p,q;
    cin>>n>>k>>p>>q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int maxi = max(p,q);
    int mini = min(p,q);

    vector<int> three,fiveThree;

    for (int i = 0; i < n; i++)
    {
        three.push_back(v[i]%mini);
        fiveThree.push_back((v[i]%maxi)%mini);
    }

    vector<int> sum(n,0);
    int hold = 0;
    for (int i = 0; i < n; i++)
    {
        if(i==0) sum[i] = min(three[i],fiveThree[i]);
        else sum[i] = sum[i-1] + min(three[i],fiveThree[i]);
    }
    hold = sum[n-1];
    for (int i = 1; i < n; i++)
    {
        three[i] += three[i-1];
        fiveThree[i] += fiveThree[i-1];
    }
    int ans = 1e15;
    
    for (int i = 0; i < n-k+1; i++)
    {
        int start = i, end = i + k - 1;
        int currAns = 0;

        int t,ft;
        int segMinSum;
        if(i==0){
            t = three[end];
            ft = fiveThree[end];
            segMinSum = sum[end];
        } 
        else{
            t = three[end] - three[start-1];
            ft = fiveThree[end] - fiveThree[start-1];
            segMinSum = sum[end] - sum[start-1] ;
        }
        ans = min(ans,min(t,ft) + hold - segMinSum);
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
