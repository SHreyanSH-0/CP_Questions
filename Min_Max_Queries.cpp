#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void build(int i,int l,int r,vector<int>&seg,vector<int>&v){
    if(l==r) seg[i] = v[l];
    else{
        int mid = (l+r)/2;

        build(2*i+1,l,mid,seg,v);
        build(2*i+2,mid+1,r,seg,v);
    
        if((r-l+1)%2==0){
            seg[i] = max(seg[2*i+1],seg[2*i+2]);
        }
        else{
            seg[i] = min(seg[2*i+1],seg[2*i+2]);
        }
    }
}

void update(int i,int l,int r,int idx,int val,vector<long long>&seg){
    if(l==r){
        seg[i] = val;
    }
    else{
        int mid = (l+r)/2;
        if(mid>=idx){
            update(2*i+1,l,mid,idx,val,seg);
        }
        else {
            update(2*i+2,mid+1,r,idx,val,seg);
        }

        if((r-l+1)%2==0){
            seg[i] = max(seg[2*i+1],seg[2*i+2]);
        }
        else{
            seg[i] = min(seg[2*i+1],seg[2*i+2]);
        }
    }
}

long long query(int start, int end, int i, int l ,int r, vector<long long>&seg){
    if(l>end||r<start) return INT_MIN;
    if(l>=start&&r<=end) return seg[i];
    int mid = (l+r)/2;

    long long a = query(start,end,2*i+1,l,mid,seg);
    long long b = query(start,end,2*i+2,mid+1,r,seg);
    
    if((start-end+1)%2==0){
        if(a==INT_MIN) return b;
        if (b==INT_MIN) return a;
        return max(a,b);
    }
    else{
        if(a==INT_MIN) return b;
        if (b==INT_MIN) return a;
        return min(a,b);
    }
}
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n),seg(4*n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    build(0,0,n-1,seg,v);

    for (int i = 0; i < q; i++)
    {
        int a,l,r;
        cin>>a>>l>>r;

        if(a==1){
            update(0,0,n-1,l-1,r,seg);
        }
        else{
            cout<<query(l-1,r-1,0,0,n-1,seg)<<endl;
        }
    }

    int p = 1;
    int idx = 0;
    cout<<"-----------------\n";
    while (idx<4*n)
    {
        for(int i=1;i<=p;i++){
            cout<<seg[idx++]<<" ";
        }cout<<endl;
        p*=2;
    }
    cout<<"-----------------\n";
    
    
    
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
