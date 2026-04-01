#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void build(int i,int l, int r , vector<int>&seg,vector<int>&arr){
    if(l==r){
        seg[i] = arr[l];
    }   
    else{
        int mid = (l+r)/2;
        build(2*i+1,l,mid,seg,arr);
        build(2*i+2,mid+1,r,seg,arr);
        seg[i] = __gcd(seg[2*i+1],seg[2*i+2]);
    }
}

int query(int start, int end, int i, int l ,int r, vector<int>&seg){
    if(l>end||r<start) return 0;
    if(l>=start&&r<=end) return seg[i];
    int mid = (l+r)/2;
    int a = query(start,end,2*i+1,l,mid,seg);
    int b = query(start,end,2*i+2,mid+1,r,seg);
    return __gcd(a,b); 
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
    
    vector<int> seg(4*n);
    build(0,0,n-1,seg,v);
    int q;
    cin>>q;

    map<int,vector<int>> map;

    for(int i=0;i<n;i++) map[v[i]].push_back(i);

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        int g = query(a,b,0,0,n-1,seg);
        int hold=0;
        if(map.find(g)!=map.end()){
            int h1 = lower_bound(map[g].begin(),map[g].end(),a) - map[g].begin();
            int h2 = upper_bound(map[g].begin(),map[g].end(),b)- map[g].begin();
            hold = h2 - h1;
        }

        cout<< b - a + 1 - hold<<endl;
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
