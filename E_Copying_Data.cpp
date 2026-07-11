#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

// void build(int i,int l,int r,vector<int> &seg, vector<int>&v){
//     if(l==r){
//         seg[i] = l;
//     }
//     else{
//         int mid = (l+r)/2;
//         build(2*i+1,l,mid,seg,v);
//         build(2*i+2,mid+1,r,seg,v);
//         seg[i] = seg[2*i+1] 
//     }
// }

void update(int start, int end, int val, int i, int l, int r, vector<int>&seg){
    if(seg[i]!=-1){
        if(l!=r){
            seg[2*i+1] = seg[i];
            seg[2*i+2] = seg[i] + (l+r)/2 - l + 1;
            seg[i] = -1;
        }
    }
    if(l>end||r<start) return;
    if(l>=start&&r<=end){
        seg[i] = val + l - start;
        if(l!=r){
            seg[2*i+1] = seg[i];
            seg[2*i+2] = seg[i] + (l+r)/2 - l + 1;
        }
        // cout<<l << " "<<r<<" "<< seg[i]<<" "<<seg[2*i+1]<<" "<<seg[2*i+2]<<endl;
        return;
    }
    
    int mid = (l+r)/2;
    
    update(start,end,val,2*i+1,l,mid,seg);
    update(start,end,val,2*i+2,mid+1,r,seg);
}
int query(int idx, int i, int l, int r, vector<int>&seg){
    if(seg[i]!=-1){
        if(l!=r){
            seg[2*i+1] = seg[i];
            seg[2*i+2] = seg[i] + (l+r)/2 - l + 1;
            seg[i] = -1;
        }
    }
    
    // cout<<l << " "<<r<<" "<< seg[i]<<" "<<seg[2*i+1]<<" "<<seg[2*i+2]<<endl;
    if(l==r) return seg[i];
    
    int mid = (l+r)/2;

    if(mid>=idx){
        return query(idx,2*i+1,l,mid,seg);
    }
    else return query(idx,2*i+2,mid+1,r,seg);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    vector<int> seg(4*n,-1);

    for (int i = 0; i < m; i++)
    {
        int t;
        cin>>t;
        if(t==1){
            int x,y,k;
            cin>>x>>y>>k;
            x--;
            y--;
            k--;
            update(y,y+k,x,0,0,n-1,seg);
        }
        else{
            int x;
            cin>>x;
            x--;
            int idx = query(x,0,0,n-1,seg);
            // cout<<idx<<" ";
            if(idx == -1) cout<<b[x]<<endl;
            else cout<<a[idx]<<endl;
        }
        // cout<<"-----\n";
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
