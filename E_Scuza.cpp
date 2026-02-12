#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n,q;
    cin>>n>>q;
    vector<ll> a(n), k(q), pre(n, 0);

    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(i==0) pre[i]=a[0];
        else pre[i]=pre[i-1]+a[i];
    } 
    
    for(int i = 0; i<q; i++) cin>>k[i];

    set<ll> s;
    map<ll,ll> m;

    for(int i = 0; i<n; i++){
        s.insert(a[i]);
        m[*s.rbegin()]=pre[i];
    }

    for(int x:k){
        auto it = s.upper_bound(x); 
        if (it == s.begin()) {
            cout << 0 << " "; 
        } else {
            --it; 
            cout << m[*it] << " ";
        }
    }
    
    cout<<"\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}