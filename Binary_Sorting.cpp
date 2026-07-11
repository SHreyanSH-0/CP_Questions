#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void update(int start, int end, int val, int i, int l, int r, vector<int>&seg, vector<int>&lazy){

    if(lazy[i]!=-1){
        if(lazy[i]==1){
            seg[i] = (r - l + 1);
            if(l!=r){
                lazy[2*i+1] = 1;
                lazy[2*i+2] = 1;
            }
        }
        else{
            seg[i] = 0;
            if(l!=r){
                lazy[2*i+1] = 0;
                lazy[2*i+2] = 0;
            }
        }
        lazy[i] = -1;
    }

    if(l>end || r<start) return;
    if(l>=start&&r<=end){
        if(val==0){
            seg[i] = 0;
            if(l!=r){
                lazy[2*i+1] = 0;
                lazy[2*i+2] = 0;
            }
        }
        else{
            seg[i] = (r - l + 1);
            if(l!=r){
                lazy[2*i+1] = 1;
                lazy[2*i+2] = 1;
            }
        }
        return;
    }
    int mid = (l+r)/2;
    update(start,end, val,2*i+1,l,mid,seg,lazy);
    update(start,end, val,2*i+2,mid+1,r,seg,lazy);
    seg[i] = seg[2*i+1] + seg[2*i+2];
}

int query(int start, int end, int i, int l, int r,vector<int>&seg,vector<int>&lazy){
    if(lazy[i]!=-1){
        if(lazy[i]==1){
            seg[i] = (r - l + 1);
            if(l!=r){
                lazy[2*i+1] = 1;
                lazy[2*i+2] = 1;
            }
        }
        else{
            seg[i] = 0;
            if(l!=r){
                lazy[2*i+1] = 0;
                lazy[2*i+2] = 0;
            }
        }
        lazy[i] = -1;
    }
    if(l>end || r<start) return 0;
    if(l>=start&&r<=end ) return seg[i];
    int mid = (l+r)/2;

    return query(start,end,2*i+1,l,mid,seg,lazy) + query(start,end,2*i+2,mid+1,r,seg,lazy);
}
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> a(n,0);
    vector<int> seg(4*n,0),lazy(4*n,-1);
    int one = -1;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin>>t;
        if(t==0){
            int start, end;
            cin>>start>>end;
            start--;
            end--;
            update(start,end, t,0,0,n-1,seg,lazy);
        }
        else if(t==1){
            int start, end;
            cin>>start>>end;
            start--;
            end--;
            update(start,end, t,0,0,n-1,seg,lazy);
        }
        else{
            int hold2 = query(0,n-1,0,0,n-1,seg,lazy);
            if(hold2>0){
                update(0,n-hold2-1, 0,0,0,n-1,seg,lazy);
                update(n-hold2,n-1, 1,0,0,n-1,seg,lazy);
            }
            cout<<1<<endl;
            continue;
        }
        int low = 0, high = n-1;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(n- mid - query(mid,n-1,0,0,n-1,seg,lazy)>0){
                low = mid + 1;
                ans = mid;
            }
            else{
                high = mid - 1;
            }
        }
        if(ans==-1) cout<<1<<endl;
        else {
            cout<<1 + query(0,ans,0,0,n-1,seg,lazy)<<endl;
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
