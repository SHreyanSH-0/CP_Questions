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
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
       
    stack<int> s;
    vector<int> nse(n,-1);
    int ans =0 ;
    for (int i = 0; i < n; i++)
    {
        if(s.empty()) s.push(i);
        else{
            bool check = false;
            while(!s.empty()&&v[s.top()]>=v[i]){
                s.pop();
            } 
            if(!s.empty()){
                if(v[i]-1==v[s.top()])nse[i] = s.top();
                else{
                    while(!s.empty()) s.pop();
                }
            }
            s.push(i);
        }
    }
    vector<int> hold(n,-1);
    for (int i = n-1; i >=0; i--)
    {
        int j = i;
        while(nse[j]!=-1){
            j = nse[j];
            hold[j]=max(hold[j],i);
        }
        hold[i] = max(hold[i],i);
    }
    // int ans =. 0;
    vector<int> a(n+1,0);
    for (int i = 0; i <n; i++)
    {
        int h = (hold[i] - i + 1);
        ans += h + (h)*(((a[i]+1)*(a[i]+2))/2 - 1);
        a[hold[i]+1]++;
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
