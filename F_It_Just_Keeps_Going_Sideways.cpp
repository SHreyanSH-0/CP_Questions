#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void update(int i,int l,int r, int idx,vector<int>&seg){
    if(l==r){
        seg[i] += 1;
    }
    else{
        int mid = (l+r)/2;
        if(idx<=mid){
            update(2*i+1,l,mid,idx,seg);
        }
        else{
            update(2*i+2,mid+1,r,idx,seg);
        }
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }
}
 
int query(int i,int l,int r,int start, int end,vector<int>&seg){
    if(l>end||r<start) return 0;
    if(l>=start&&r<=end) return seg[i];
    int mid = (l+r)/2;
    return query(2*i+1,l,mid,start,end,seg) + query(2*i+2,mid+1,r,start,end,seg) ;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n),seg(4*(n+1),0);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> nge(n,-1), sorted= v;
    stack<int> st;
    int ans = 0, val = 0;

    sort(sorted.begin(),sorted.end());

    for (int i = 0; i < n; i++)
    {
        sorted[i] = v[i] - sorted[i];
    }
    for (int i = 1; i < n; i++)
    {
        sorted[i] += sorted[i-1];
    }
    for (int i = 0; i < n; i++)
    {
        val += sorted[i];
    }
    

    for (int i=n-1; i>=0; i--)
    {
        while(!st.empty()&&v[st.top()]<=v[i]) st.pop();
        if(!st.empty()) nge[i] = st.top() -1;
        else nge[i] = n-1;
        st.push(i); 
    }

    update(0,0,n,v[0],seg);
    
    for (int i = 1; i < n; i++)
    {
        int less = query(0,0,n,v[i],n,seg);
        int hold = val - (nge[i] - i) + less;

        ans = max(ans,hold);
        update(0,0,n,v[i],seg);
    }
    cout<<ans<<endl;
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