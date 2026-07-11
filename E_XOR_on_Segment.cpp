#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void build(int i,int l,int r,vector<vector<int>>&seg,vector<int>&v){
    if(l==r){
        int hold = v[l];
        int idx = 0;
        while(hold>0){
            seg[i][idx++] = hold%2;
            hold/=2; 
        }
    }
    else{
        int mid = (l+r)/2;
        build(2*i+1,l,mid,seg,v);
        build(2*i+2,mid+1,r,seg,v);
        for (int j = 0; j < 30; j++)
        {
            seg[i][j] = seg[2*i+1][j] + seg[2*i+2][j];
        }
    }
}

void update(int i,int l,int r, int start,int end, int x,vector<vector<int>>&seg, vector<int> &lazy){
    if(lazy[i]!=0){
        int hold = lazy[i];
        int idx = 0;
        int total = r - l + 1;
        while(hold>0){
            if(hold%2==1){
                int curr = seg[i][idx];
                int now = total - seg[i][idx];
                seg[i][idx] = now;
            } 
            hold/=2; 
            idx++;
        }
        if(l!=r){
            lazy[2*i+1] ^= lazy[i];
            lazy[2*i+2] ^= lazy[i];
        }
        lazy[i] = 0;
    }
    if(start>end) return;
    if(l>end||r<start) return;
    if(l>=start&&r<=end) {
        int hold = x;
        int idx = 0;
        int total = r - l + 1;
        while(hold>0){
            if(hold%2==1){
                int curr = seg[i][idx];
                int now = total - seg[i][idx];
                seg[i][idx] = now;
            } 
            hold/=2; 
            idx++;
        }

        if(l!=r){
            lazy[2*i+1] ^= x;
            lazy[2*i+2] ^= x;
        }
        return;
    }
    int mid = (l+r)/2;
    update(2*i+1,l,mid,start,end,x,seg,lazy);
    update(2*i+2,mid+1,r,start,end,x,seg,lazy); 
    for (int j = 0; j < 30; j++)
    {
        seg[i][j] = seg[2*i+1][j] + seg[2*i+2][j];
    } 
}

vector<int> query(int start, int end, int i,int l,int r, vector<vector<int>>&seg,vector<int>&lazy){
    if(lazy[i]!=0){
        int hold = lazy[i];
        int idx = 0;
        int total = r - l + 1;
        while(hold>0){
            if(hold%2==1){
                int curr = seg[i][idx];
                int now = total - seg[i][idx];
                seg[i][idx] = now;
            } 
            hold/=2; 
            idx++;
        }
        if(l!=r){
            lazy[2*i+1] ^= lazy[i];
            lazy[2*i+2] ^= lazy[i];
        }
        lazy[i] = 0;
    }
    if(start>end) return vector<int>(30,0);
    if(l>end||r<start) return vector<int>(30,0);
    if(l>=start&&r<=end) return seg[i];
    int mid = (l+r)/2;
    vector<int> a = query(start,end,2*i+1,l,mid,seg,lazy);
    vector<int> b = query(start,end,2*i+2,mid+1,r,seg,lazy);

    for(int j=0;j<30;j++){
        a[j] +=b[j];
    }
    return a;
}


void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    vector<vector<int>> seg1(4*n,vector<int>(30,0));
    vector<int> lazy(4*n,0);
    build(0,0,n-1,seg1,v);
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int ti;
        cin>>ti;
        if(ti==1){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            vector<int> hold = query(l,r,0,0,n-1,seg1,lazy);
            int ans = 0;
            for(int i=0;i<30;i++){
                ans += (1<<i)*hold[i];
            }
            cout<<ans<<endl;
        }
        else{
            int l,r,x;

            cin>>l>>r>>x;
            l--;
            r--;
            update(0,0,n-1,l,r,x,seg1,lazy);
        }
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
