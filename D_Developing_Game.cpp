#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void update(int i,int l,int r, int val,int idx,vector<int>&seg){
    if(l==r){
        seg[i]++;
    }
    else{
        int mid = (l+r)/2;
        if(mid>=idx) update(2*i+1,l,mid,val,idx,seg);
        else update(2*i+2,mid+1,r,val,idx,seg);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }
}

int query(int start,int end, int i,int l,int r,vector<int>&seg){
    if(start>r||end<l) return 0;
    if(l>=start&&r<=end) return seg[i];
    int mid = (l+r)/2;
    return query(start,end,2*i+1,l,mid,seg) + query(start,end,2*i+2,mid+1,r,seg) ;
}

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(2));
    vector<int> a(n),b;
    for (int i = 0; i < n; i++)
    {
        int b,c;
        cin>>b>>a[i]>>c;
        v[i] = {b,c};
    }
    
    sort(a.begin(),a.end());
    map<int,int> map;
    int ans = 0;
    vector<int> seg(4*n,0);
    int ct = 0;
    for(int i=0;i<n;i++){
        if(map.find(a[i])==map.end())
        map[a[i]] = ct++; 
        update(0,0,n-1,1,map[a[i]],seg);
    } 

    for (int i = 0; i < n; i++)
    {
        cout<<v[i][0]<<" "<<v[i][1]<<" "<<query(v[i][0],v[i][1],0,0,n-1,seg)<<endl;
        ans = max(ans, query(v[i][0],v[i][1],0,0,n-1,seg));
    }

    cout<<ans<<endl;
    
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
