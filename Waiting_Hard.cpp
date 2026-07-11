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
    vector<int> pref(n,0), nge(n,-1);

    int ans = 0;

    pref[0] = v[0];

    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i-1] + v[i];
    }
    stack<int> st;

    for (int i = n-1; i>=0; i--)
    {
        while(!st.empty() && v[i] >= v[st.top()]) st.pop();
        if(!st.empty()) nge[i] = st.top();
        st.push(i);
    }
    vector<int> hold(n);
    for (int i = 0; i < n; i++)
    {
        int idx = nge[i];
        if(idx == -1){
            int sum = pref[n-1] - pref[i];
            hold[i] = (n-1 - i)*v[i] - sum;
        }
        else{
            int sum = pref[idx-1] - pref[i];
            hold[i] = (idx - i - 1)*v[i] - sum;
        }
    }

    for (int i = 0; i < n; )
    {
        if(i==-1) break;
        ans += hold[i];
        i = nge[i];
    }
    
    int sum = 0;

    int prev = -1;
    int ansh = ans;

    vector<int> pref2(n,0);

    for (int i = n-1; i>=0; i--)
    {
        int j = i;
        if(nge[i] == -1){
            pref2[i] = hold[i];
        }
        else pref2[i] = hold[i] + pref2[nge[i]];
    }

    for (int i = 0; i < n;)
    {
        if(i==-1) break;
        if(hold[i] > 0){
            int l= nge[i] == -1? n : nge[i];
            int j;
            int ct = 0;
            for(j=i+1;j<l;j++){
                if(v[j] > prev){
                    break;
                }
                else ct += (-v[j] + prev);
            }
            // cout<<i<<" "<<j<<" "<<ct<<endl;
            if(j == l){
                ansh = min(ansh, ans -  hold[i] + ct);
            }
            else{
                if(j!=-1) ct += pref2[j];
                int val = nge[i] == -1? 0 : pref2[nge[i]];
                ansh = min(ansh, ans - hold[i] + ct - val);
            }
        }
        prev = v[i];
        i = nge[i];
    }
    sum = 0;
    int time = 1;
    for (int i = 0; i < n; i++)
    {
        if(v[i] >= time){
            time = v[i];
            hold[i] = 0;
        }
        else{
            sum += time - v[i];
            hold[i] = time - v[i];
        } 
        // cout<<hold[i]<<" ";
    }
    // cout<<endl;

    for (int i = 0; i < n; i++)
    {
        ansh = min(ansh , sum - hold[i]);
    }
    
    
    cout<<ansh<<endl;
    
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
