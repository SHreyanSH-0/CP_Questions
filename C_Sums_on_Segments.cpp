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
    int idx = -1;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(v[i]!=-1&&v[i]!=1) idx = i;
    }
    if(idx==-1){
        idx = n;
        int one = 0, mone = 0;
        int sum = 0;
        for (int i = 0; i <idx; i++)
        {
            sum += v[i];
            if(sum<0) sum = 0;
            one = max(one,sum);
        }
        sum = 0;
        for (int i = 0; i <idx; i++)
        {
            sum += v[i];
            if(sum>0) sum = 0;
            mone = min(mone,sum);
        }

        for(int i=0;i<=one;i++) s.insert(i);
        for(int i=0;i>=mone;i--) s.insert(i);
    }
    else{
        int sum = 0;
        int maxiL =INT_MIN, miniL = 1e8;
        int maxiR =INT_MIN, miniR = 1e8;
        for (int i = idx-1; i >=0; i--)
        {
            sum += v[i];
            maxiL = max(maxiL,sum);
            miniL = min(miniL,sum);
        }
        sum = 0;
        for (int i = idx+1; i <n; i++)
        {
            sum += v[i];
            maxiR = max(maxiR,sum);
            miniR = min(miniR,sum);
        }

        if(maxiL<0) maxiL = 0;
        if(maxiR<0) maxiR = 0;
        if(miniL>0) miniL = 0;
        if(miniR>0) miniR = 0;


        int one = 0, mone = 0;
        sum = 0;
        for (int i = 0; i <idx; i++)
        {
            sum += v[i];
            if(sum<0) sum = 0;
            one = max(one,sum);
        }
        sum = 0;
        for (int i = 0; i <idx; i++)
        {
            sum += v[i];
            if(sum>0)  sum= 0;
            mone = min(mone,sum);
        }
        sum = 0;
        for (int i = idx+1; i <n; i++)
        {
            sum += v[i];
            if(sum<0) sum = 0;
            one = max(one,sum);
        }
        sum = 0;
        for (int i = idx+1; i <n; i++)
        {
            sum += v[i];
            if(sum>0) sum = 0;
            mone = min(mone,sum);
        }

        for(int i=0;i<=one;i++) s.insert(i);
        for(int i=0;i>=mone;i--) s.insert(i);
        int val = v[idx];

        int mini = miniL + miniR;
        int maxi = maxiL + maxiR;
        for(int i=0;i<=maxi;i++) s.insert(i + val);
        for(int i=0;i>=mini;i--) s.insert(i + val);
        
    }
    cout<<s.size()<<endl;
    for (auto&it : s)
    {
        cout<<it<<" ";
    }
    
    cout<<endl;
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
