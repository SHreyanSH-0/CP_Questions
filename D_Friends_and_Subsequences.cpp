#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

class MinSegmentTree {
public:
    vector<int> seg;
    int n;

    MinSegmentTree(vector<int>& v) {
        n = v.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, v);
    }

    void build(int idx, int l, int r, vector<int>& v) {
        if(l == r) {
            seg[idx] = v[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx + 1, l, mid, v);
        build(2 * idx + 2, mid + 1, r, v);

        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if(r < ql || l > qr) return 1e18;

        if(ql <= l && r <= qr) return seg[idx];

        int mid = (l + r) / 2;

        return min(
            query(2 * idx + 1, l, mid, ql, qr),
            query(2 * idx + 2, mid + 1, r, ql, qr)
        );
    }

    void update(int idx, int l, int r, int pos, int val) {
        if(l == r) {
            seg[idx] = val;
            return;
        }

        int mid = (l + r) / 2;

        if(pos <= mid)
            update(2 * idx + 1, l, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, r, pos, val);

        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};

class MaxSegmentTree {
public:
    vector<int> seg;
    int n;

    MaxSegmentTree(vector<int>& v) {
        n = v.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, v);
    }

    void build(int idx, int l, int r, vector<int>& v) {
        if(l == r) {
            seg[idx] = v[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx + 1, l, mid, v);
        build(2 * idx + 2, mid + 1, r, v);

        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if(r < ql || l > qr) return -1e18;

        if(ql <= l && r <= qr) return seg[idx];

        int mid = (l + r) / 2;

        return max(
            query(2 * idx + 1, l, mid, ql, qr),
            query(2 * idx + 2, mid + 1, r, ql, qr)
        );
    }

    void update(int idx, int l, int r, int pos, int val) {
        if(l == r) {
            seg[idx] = val;
            return;
        }

        int mid = (l + r) / 2;

        if(pos <= mid)
            update(2 * idx + 1, l, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, r, pos, val);

        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};







void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    
    MinSegmentTree bseg(b);
    MaxSegmentTree aseg(a);


    for (int i = 0; i < n; i++)
    {
        int low = i, high = n-1;
        int mini = -1, maxi =  -1;
        while(low<=high){
            int mid = (low + high )/2;
            int x = aseg.query(0, 0, n - 1, i, mid);
            int y = bseg.query(0, 0, n - 1, i, mid);
            if(x==y){
                mini = mid;
                high = mid - 1;
            }
            else if(x < y){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        low = i, high = n-1;
        while(low<=high){
            int mid = (low + high )/2;

            int x = aseg.query(0, 0, n - 1, i, mid);
            int y = bseg.query(0, 0, n - 1, i, mid);
            if(x==y){
                maxi = mid;
                low = mid + 1;
            }
            else if(x < y){
                low = mid +1 ;
            }
            else{
                high = mid - 1;
            }
        }

        if(maxi==-1||mini==-1) continue;

        ans += maxi - mini + 1;
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
