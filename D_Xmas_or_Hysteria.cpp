#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(2,0));
    for (int i = 0; i < n; i++)
    {
        cin>>v[i][0];
        v[i][1] = i+1;
    }

    sort(v.begin(),v.end());
    
    if(m==0){
        int sum = 0;
        int hold = -1;
        vector<vector<int>> ans;
        for (int i = 0; i < n-1; i++)
        {
            if(v[n-1][0] - sum<=v[n-2][0]){
                hold = i;
                break;
            }
            sum += v[i][0];
        }

        if(hold==-1) {
            cout<<-1<<endl;
        }
        else{
            for (int i = 0; i < hold; i++)
            {
                ans.push_back({v[i][1],v[n-1][1]});
            }
            
            for (int i = hold; i < n-1; i++)
            {
                ans.push_back({v[i][1],v[i+1][1]});
            }
            
            cout<<ans.size()<<endl;
            for (int i = 0; i < ans.size(); i++)
            {
                cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
            }
        }
        
        return;
    }
 
    if(2*m>(n)){
        cout<<-1<<endl;
        return;
    }

    vector<int> hold;
    vector<vector<int>> ans;
    
    for (int i = 1; i < 2*m; i+=2)
    {
        hold.push_back(v[i][1]);
        ans.push_back({v[i][1], v[i-1][1]});
    }

    for (int i = 2*m; i < n;)
    {
        for (int j = 0; j < hold.size()&&i<n; j++)
        {
            ans.push_back({v[i][1],hold[j]});
            hold[j] = v[i++][1];
        }
    }

    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
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
