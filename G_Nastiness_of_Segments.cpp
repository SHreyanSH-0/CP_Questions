#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void build(int i, int l, int r, int seg[], vector<int>&arr){
    if(l==r) seg[i] =arr[l];
    else{
        int mid = (l+r)/2;
        build(2*i+1,l,mid,seg,arr);
        build(2*i+2,mid+1,r,seg,arr);
        seg[i] = min(seg[2*i+1],seg[2*i+2]);
    }
}

void update(int idx, int val, int i, int l, int r, int seg[]){
    if(l==r) seg[i] = val;
    else{
        int mid = (l+r)/2;
        if(idx<=mid) update(idx,val,2*i+1,l,mid,seg);
        else update(idx,val,2*i+2,mid+1,r,seg);
        seg[i] = min(seg[2*i+1],seg[2*i+2]);
    }
}

int query(int s, int e, int i,int l, int r, int seg[]){
    if(l>e||r<s) return LLONG_MAX;
    if(l>=s&&r<=e) return seg[i];
    int mid = (l+r)/2;
    return min(query(s,e,2*i+1,l,mid,seg),query(s,e,2*i+2,mid+1,r,seg));
}

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    int seg[4*n];
    
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    build(0,0,n-1,seg,v);

    for (int i = 0; i < q; i++)
    {
        int op;
        cin>>op;
        if(op==1){
            int i,x;
            cin>>i>>x;
            update(i-1,x,0,0,n-1,seg);
        }
        else{
            int l,r;
            cin>>l>>r;
            int low = 1, high = r - l;
            bool check = false;
            while(low<=high){
                int mid = (low+high)/2;
                int hold = query(l-1,l-1 + mid,0,0,n-1,seg);
                if(hold == mid) {
                    check = true;
                    break;
                }
                else if(hold>mid){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            cout<<check<<endl;
        }
    }
    
    
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
