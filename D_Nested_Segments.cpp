#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void update(int i,int l,int r, int idx,int val, vector<int> &seg){
    if(l==r){
        seg[i]+=val;
    }
    else{
        int mid = (l+r)/2;
        if(mid>=idx){
            update(2*i+1,l,mid,idx,val,seg);
        }
        else{
            update(2*i+2,mid+1,r,idx,val,seg);
        }
        seg[i] = seg[2*i+1] + seg[2*i+2]; 
    }
}

int query(int start, int end, int i,int l,int r, vector<int>&seg){
    if(start>end) return 0;
    if(l>end||r<start) return 0;
    if(l>=start&&r<=end) return seg[i];
    int mid = (l+r)/2;
    return query(start,end,2*i+1,l,mid,seg)+query(start,end,2*i+2,mid+1,r,seg);
}

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> nums(n);
    vector<int> sorted;
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i].first>>nums[i].second;
        sorted.push_back(nums[i].first);
        sorted.push_back(nums[i].second);
    }
    sort(sorted.begin(),sorted.end());
    
    int idx = 0;
    map<int,int> comp;
    for (int i = 0; i < sorted.size(); i++)
    {
        if(comp.find(sorted[i])==comp.end()){
            comp[sorted[i]] = idx++;
        }
    }
    
    int ct = 0;
    vector<int> seg1(4*idx,0),seg2(4*idx,0);
    
    
    
    
    
    
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
