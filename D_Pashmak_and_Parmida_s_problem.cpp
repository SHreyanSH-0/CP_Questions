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
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    
    vector<int> ans(nums.size(),0), ans2(nums.size(),0);
    map<int,int> map1,map2;

    for(int i= n-1;i>=0;i--){
        map1[nums[i]]++;
        ans2[i] = map1[nums[i]];
    }

    for (int i = 0; i < n; i++)
    {
        map2[nums[i]]++;
        ans[i] = map2[nums[i]];
    }

    int idx = 0;
    vector<int> seg(4*n);
    map<int,int> comp;
    vector<int> sorted = ans2;
    sort(sorted.begin(),sorted.end());
    for (int i = 0; i < n; i++)
    {
        sorted.push_back(ans[i]);
    }
    for (int i = 0; i < sorted.size(); i++)
    {
        if(comp.find(sorted[i])==comp.end())
        comp[sorted[i]] = idx++;
    }

    
    int ct = 0;
    for(int i= n-1;i>=0;i--){
        if(i==n-1){
            update(0,0,idx-1,comp[ans2[i]],1,seg);
        }
        else{
            ct += query(0,comp[ans[i]]-1,0,0,idx-1,seg);
            update(0,0,idx-1,comp[ans2[i]],1,seg);
        }
    }




    cout<<ct<<endl;
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
