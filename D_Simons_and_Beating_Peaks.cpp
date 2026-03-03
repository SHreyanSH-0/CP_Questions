#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void build(int i,int l,int r, vector<int>&seg, vector<int>&v){
    if(l==r) seg[i] = l;
    else{
        int mid = (l+r)/2;
        build(2*i+1,l,mid,seg,v);
        build(2*i+2,mid+1,r,seg,v);
        if(v[seg[2*i+1]]>v[seg[2*i+2]]) seg[i] = seg[2*i+1];
        else seg[i] = seg[2*i+2];
    }
}

int query(int start, int end , int i, int l, int r, vector<int>&seg,vector<int>&v){
    if(l>end||r<start) return -1;
    if(l>=start&&r<=end) return seg[i];
    int mid = (l+r)/2;
    int a = query(start,end,2*i+1,l,mid,seg,v);
    int b = query(start,end,2*i+2,mid+1,r,seg,v);
    if(a==-1) return b;
    else if(b==-1) return a;
    else if(v[a]>v[b]) return a;
    else return b;
}

int rec(vector<int>&v, vector<int>&seg, int low, int high){
    if(low>=high) return 0;
    int ind = query(low,high,0,0,v.size()-1,seg,v);
    int a = rec(v,seg,low,ind-1) + high - ind;
    int b = rec(v,seg,ind + 1,high) + ind - low;
    return min(a,b);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> seg(4*n);
    for(int i= 0;i<n;i++) cin>>v[i];
    build(0,0,n-1,seg,v);

    cout<<rec(v,seg,0,n-1)<<endl;
    
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
