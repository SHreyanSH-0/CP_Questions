#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void update(int idx, int i, int l, int r, vector<int>&seg){
    if(l==r) seg[i]++;
    else{
        int mid = (l+r)/2;
        if(mid < idx) update(idx, 2*i+2,mid+1,r,seg);
        else update(idx,2*i+1,l,mid,seg);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }
}

int query(int start, int end, int i, int l, int r, vector<int>&seg){
    if(start > end) return 0;
    if( l > end || r < start) return 0;
    if(l>=start && r<=end) return seg[i];
    int mid = (l+r)/2;
    return query(start,end,2*i+1,l,mid,seg) + query(start,end,2*i+2,mid+1,r,seg) ;
}


void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    vector<int> hold(n);
    for (int i = 0; i < n; i++)
    {
        hold[i] = b[i] - a[i];
        a[i] = a[i] - b[i];
    }


    b = {};

    for(int i=0;i<n;i++) {
        b.push_back(a[i]);
        b.push_back(hold[i]);
    }

    sort(b.begin(),b.end());

    unordered_map<int,int> map;
    int ct = 0;

    for (int i = 0; i < 2*n; i++)
    {
        if(map.find(b[i]) == map.end()) map[b[i]] = ct++;
    }

    vector<int> seg(4*ct, 0);

    int ans = 0;

    for(int i=0;i<n;i++){
        ans += query(map[hold[i]] + 1, ct-1, 0,0,ct-1,seg);
        update(map[a[i]],0,0,ct-1,seg);
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
