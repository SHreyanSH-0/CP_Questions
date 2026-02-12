#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void build(int i, int l, int r, int seg[],vector<int> &arr){
    if(l==r) seg[i] = arr[l];
    else {
        int mid = (l+r)/2;
        build (2*i+1,l,mid,seg,arr);
        build (2*i+2,mid+1,r,seg,arr);
        seg[i]=(seg[2*i+1] ^ seg[2*i+2]);
    }
}

int  update(int idx, int val, int i, int l, int r, int seg[]){
    int ans = 0;
    if(l==r){
        seg[i] = val;
    } 
    else{
        int mid = (l+r)/2;
        if(idx<=mid){
            ans = update(idx,val,2*i+1,l,mid,seg);
            if(seg[2*i+1]>=seg[2*i+2]){
                ans += (r - mid);
            }
        }
        else{
            ans = update(idx,val,2*i+2,mid+1,r,seg);
            if(seg[2*i+1]<seg[2*i+2]){
                ans += (mid - l + 1);
            }
        }
        seg[i]=(seg[2*i+1] ^ seg[2*i+2]);
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int n1 = 1 << n;
    vector<int> a(n1);
    int seg[4*n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    build(0,0,n1-1,seg,a);
    
    for (int i = 0; i < k; i++)
    {
        int b, c;
        cin >> b >> c;
        b--;
        cout<<n1 - update(b,c,0,0,n1-1,seg) - 1<<endl;
        update(b,a[b],0,0,n1-1,seg);
    }

}
signed main()
{

    ll test = 1;
    cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
