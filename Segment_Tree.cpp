#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

vector<int> arr = {1,2,3,4,5,6};
int seg[4*6];
void build_tree(int i, int l, int r){
    if(l==r) seg[i] = arr[l];
    else{
        int mid = (l+r)/2;
        build_tree(2*i+1, l,mid);
        build_tree(2*i+2,mid+1,r);
        seg[i] = max(seg[2*i+1],seg[2*i+2]);
    }
}

void update(int idx, int val , int i, int l, int r){
    if(l==r){
        seg[i] = val;
    }
    else{
        int mid = (l+r)/2;
        if(idx<=mid){
            update(idx,val,2*i+1,l,mid);
        }
        else{
            update(idx,val,2*i+2,mid+1,r);
        }
        seg[i] = max(seg[2*i + 1] , seg[2*i + 2]);
    }
}

void updateRange(int start, int end, int i, int l, int r, int val,int lazy[]){
    int mid = (l+r)/2;
    if(lazy[i]!=0){
        seg[i] += lazy[i];
        if(l!=r){
            lazy[2*i+1] = lazy[i];
            lazy[2*i+2] = lazy[i];
        }
        lazy[i] = 0;
    }
    if(l>end||r<start) return;

    if(l>=start&&r<=end){
        seg[i] += val;
        if(l!=r){
            seg[2*i+1] += val;
            seg[2*i+2] += val;
        }
        return;
    }
    updateRange(start,end,2*i+1,l,mid,val,lazy);
    updateRange(start,end,2*i+2,mid+1,r,val,lazy);
    seg[i] = max(seg[2*i+1] , seg[2*i+2]);
}

int query(int start, int end, int i, int l , int r){
    if(l>end||r<start) return -1e8;
    if(l>=start&&r<=end) return seg[i];
    int mid = (l+r)/2;
    return max(query(start, end, 2*i+1, l,mid) , query(start,end,2*i+2,mid+1, r));
}


void solve()
{
    build_tree(0,0,5);
    // for (int i = 0; i < sizeof(seg)/sizeof(seg[0]); i++)
    // {
    //     cout<<seg[i]<<" ";
    // }cout<<endl;
    // update(0,10,0,0,5);
    // for (int i = 0; i < sizeof(seg)/sizeof(seg[0]); i++)
    // {
    //     cout<<seg[i]<<" ";
    // }cout<<endl;
    // update(0,1,0,0,5);
    // for (int i = 0; i < sizeof(seg)/sizeof(seg[0]); i++)
    // {
    //     cout<<seg[i]<<" ";
    // }cout<<endl;

    // while(true){
    //     int a, b;
    //     cin>>a>>b;
    //     if(a==-1) return;
    //     cout<<query(a,b,0,0,5)<<endl;
    // }
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    int lazy[4*6];
    memset(lazy,0,sizeof(lazy));
    while(true){
        int a, b, val;
        cin>>a>>b>>val;
        if(a==-1) return;
        updateRange(a,b,0,0,5,val,lazy);
        cout<<query(a,b,0,0,5)<<endl;
    }    
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
