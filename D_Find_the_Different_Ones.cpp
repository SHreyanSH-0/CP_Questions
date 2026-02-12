#include <bits/stdc++.h>
using namespace std;
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
    int q;
    cin>>q;
    vector<pair<pair<int,int>,int>> query(q);
    vector<pair<int,int>> check;
    for (int i = 0; i < q; i++)
    {
        int a ,b;
        cin>>a;
        cin>>b;
        query[i] = {{a,b},i};

    }
    vector<int> hold;
    int h = v[0];
    hold.push_back(0);
    for (int i = 0; i < n; i++)
    {
        if(v[i]!=h){
            h = v[i];
            hold.push_back(i);
        }
    }

    for (int i = 0; i < hold.size(); i++)
    {
        if(i==hold.size()-1){
            check.push_back({hold[i]+1,n});
        }
        else{
            check.push_back({hold[i]+1,hold[i+1]});
        }
    }
    int j = 0;

    sort(query.begin(),query.end());
    vector<pair<int,int>> ans(q);
    for (int i = 0; i < q; i++)
    {
        int a = query[i].first.first;
        int b = query[i].first.second;
        for (j; j < check.size(); j++)
        {
            if(a >= check[j].first && a<=check[j].second){
                if(b<=check[j].second){
                    ans[query[i].second] = {-1,-1};
                }
                else{
                    ans[query[i].second] = {a,check[j+1].first};
                }
                break;
            }
        }        
    }
    for (int i = 0; i < q; i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    
    cout<<endl;
    
}
int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
