#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void update(int i,int l,int r, int idx,vector<int>&seg){
    if(l==r){
        seg[i] += 1;
    }
    else{
        int mid = (l+r)/2;
        if(idx<=mid){
            update(2*i+1,l,mid,idx,seg);
        }
        else{
            update(2*i+2,mid+1,r,idx,seg);
        }
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }
}

int query(int i,int l,int r,int start, int end,vector<int>&seg){
    if(l>end||r<start) return 0;
    if(l>=start&&r<=end) return seg[i];
    int mid = (l+r)/2;
    return query(2*i+1,l,mid,start,end,seg) + query(2*i+2,mid+1,r,start,end,seg) ;
}


void solve()
{
    int n;
    cin>>n;
    vector<int> v(n),seg(4*n,0);
    map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        map[v[i]]++;
    }

    int idx = 0;
    for(auto&it:map){
        map[it.first] = idx++;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(i==0) update(0,0,n-1,map[v[i]],seg);
        else{
            int lower = query(0,0,n-1,0,map[v[i]]-1,seg);
            int higher = query(0,0,n-1,map[v[i]]+1,map.size()-1,seg);
            ans += min(higher , lower);
            update(0,0,n-1,map[v[i]],seg);
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
