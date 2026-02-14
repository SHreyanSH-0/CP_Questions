#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void build(int i,int l,int r, int seg[], int h,int bit,vector<int> &arr){
    if(l==r) seg[i] = arr[l];
    else{
        int mid = (l+r)/2;
        build(2*i+1,l,mid,seg,h+1,bit,arr);
        build(2*i+2,mid+1,r,seg,h+1,bit,arr);
        if(h%2==bit){
            seg[i] = (seg[2*i+1]^seg[2*i+2]);
        }
        else{
            seg[i] = (seg[2*i+1]|seg[2*i+2]);
        }
    }
}

void update(int idx, int val , int i, int l, int r,int seg[],int h, int bit){
    if(l==r){
        seg[i] = val;
    }
    else{
        int mid = (l+r)/2;
        if(idx<=mid){
            update(idx,val,2*i+1,l,mid,seg,h+1,bit);
        }
        else{
            update(idx,val,2*i+2,mid+1,r,seg,h+1,bit);
        }
        if(h%2==bit){
            seg[i] = (seg[2*i + 1]^seg[2*i + 2]);
        }
        else{
            seg[i] = (seg[2*i + 1]|seg[2*i + 2]);
        }
    }
}

void solve()
{
    int n,q;
    cin>>n>>q;
    int n1 = n;
    n = (1<<n);
    vector<int> v(n);
    int seg[2*n];
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    build(0,0,n-1,seg,1,(n1+1)%2,v);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        update(a-1,b,0,0,n-1,seg,1,(n1+1)%2);
        cout<<seg[0]<<endl;
    }
    
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
