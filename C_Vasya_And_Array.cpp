#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

vector<pair<int,int>> merge(vector<pair<int,int>>&v){
    if(v.empty()) return {};
    vector<pair<int,int>> ans;

    ans.push_back(v[0]);

    for(int i=1;i<v.size();i++){
        if(ans[ans.size()-1].second>=v[i].second) continue;
        else if(ans[ans.size()-1].second < v[i].first){
            ans.push_back(v[i]);
        }
        else{
            int start = ans[ans.size()-1].first;
            int end = v[i].second;
            ans.pop_back();
            ans.push_back({start,end});
        }
    }
    return ans;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> one, zero;

    for(int i=0;i<m;i++){
        int c,a,b;
        cin>>c>>a>>b;
        if(c ==0){
            zero.push_back({a,b});
        }
        else{
            one.push_back({a,b});
        }
    }

    sort(one.begin(),one.end());
    sort(zero.begin(),zero.end());    
    one = merge(one);

    vector<int> ans(n+1,-1);
    int hold = 10000;
    for(int i=one.size()-1;i>=0;i--){
        for(int j=one[i].first;j<=one[i].second;j++){
            ans[j] = hold;
        }
        hold+=10000;
    }

    for(int i=0;i<zero.size();i++){
        hold = 1e9;
        for(int j=zero[i].first;j<=zero[i].second;j++,hold--){
            if(j-1>0){
                if(ans[j]==-1&&ans[j-1]!=-1)
                ans[j] = ans[j-1] - 1;
                else if(ans[j]==-1)
                ans[j] = hold;
            }
            else{
                if(ans[j]==-1)
                ans[j] = hold;
            }
        }
    }
    bool can = true;
    for(int i=zero.size()-1;i>=0;i--){
        bool check = false;
        for(int j=zero[i].first;j<zero[i].second;j++){
            if(ans[j]>ans[j+1]) check = true;
        }
        if(!check) {
            can = false;
            break;
        }
    }
    if(can){
        cout<<"YES"<<endl;
        for (int i = 1; i <= n; i++)
        {
            if(ans[i]==-1) ans[i] = 69;
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else cout<<"NO"<<endl;
    
    
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
