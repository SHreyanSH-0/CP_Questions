#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void build(int i, int l, int r,vector<int> &seg, vector<int> &v){
    if(l==r) seg[i] = v[l];
    else{
        int mid = (l+r)/2;
        build(2*i+1,l,mid,seg,v);
        build(2*i+2,mid+1,r,seg,v);
        seg[i] = min(seg[2*i + 2],seg[2*i+1]);
    }
}

int query(int start,int end, int i, int l, int r, vector<int>&seg,vector<int>&lazy){
    if(lazy[i]!=0){
        seg[i] += lazy[i];
        if(l!=r){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(l>end||r<start) return LLONG_MAX;
    if(l>=start&&r<=end) return seg[i];
    int mid = (l+r)/2;
    return min(query(start,end,2*i+1,l,mid,seg,lazy),query(start,end,2*i+2,mid+1,r,seg,lazy));
}

void add(int start, int end, int i , int l, int r, vector<int>&seg, vector<int>&lazy,int v){
    // cout<<l<<" "<<r<<endl;
    if(lazy[i]!=0){
        seg[i] += lazy[i];
        if(l!=r){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    
    if(l>end||r<start) return;
    if(l>=start&&r<=end) {
        seg[i] +=v;
        if(l!=r){
            lazy[2*i+1] += v;
            lazy[2*i+2] += v;
        }
        return;
    }
    int mid = (l+r)/2;
    add(start,end,2*i+1,l,mid,seg,lazy,v);
    add(start,end,2*i+2,mid+1,r,seg,lazy,v);
    seg[i] = min(seg[2*i+1],seg[2*i+2]);
    
}   

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n), seg(4*n),lazy(4*n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    build(0,0,n-1,seg,v);
    int q;
    cin>>q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < q; i++)
    {
        string s;
        getline(cin, s);
        vector<int> hold;
        int a = 0;
        bool neg = false;
        for(int i=0;i<s.size();i++) {
            if(i==s.size()-1){
                a = a*10 + (s[i]-'0');
                if(neg) a = -a;
                hold.push_back(a);
            }
            if(s[i]==' '){
                hold.push_back(a);
                a = 0;
                continue;
            }
            if(s[i]=='-') {
                neg = true;
                continue;
            }
            a = a*10 + (s[i] - '0');
        }
        if(hold.size()==2){
            // cout<<hold[0]<<" "<<hold[1]<<endl;
            if(hold[0]>hold[1]){
                cout<<min(query(hold[0],n-1,0,0,n-1,seg,lazy),query(0,hold[1],0,0,n-1,seg,lazy))<<endl;
            }
            else{
                cout<<query(hold[0],hold[1],0,0,n-1,seg,lazy)<<endl;
            }
        }
        else{
            // cout<<hold[0]<<" "<<hold[1]<<" "<<hold[2]<<endl;
            if(hold[0]>hold[1]){
                add(hold[0],n-1,0,0,n-1,seg,lazy,hold[2]);
                add(0,hold[1],0,0,n-1,seg,lazy,hold[2]);
            }
            else{
                add(hold[0],hold[1],0,0,n-1,seg,lazy,hold[2]);
            }
        }
        // cout<<"end"<<endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<query(i,i,0,0,n-1,seg,lazy)<<" ";
    // }cout<<endl;
    
    
    
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
