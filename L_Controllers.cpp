#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const ll inf = 2e18 + 5;
const ll M = 1e9 + 7;

void solve(){

    int n;
    cin>>n;

    vector<int>v(n);

    map<int, int>mp;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        mp[v[i]]++;
    }
    int cnt = 0;
    for(auto &[x,y]: mp) {
        if(y%2==0) {
            cnt+=(y);
        }
        else {
            cnt+=(y-1);
        }
    }

    set<int>p;
    for(int i=0;i<n;i++) {
        if(mp[v[i]]%2==1) {
            p.insert(v[i]);
        }
    }

    int ans = 0;
    for(auto &[x,y]: mp) {
        if(y%2==0) {
            ans+=(x*y);
        }
        else {
            ans+=(x*(y-1));
        }
    }

    int prnt = ans;

    vector<int>dum;
    for(auto &x: p) {
        dum.push_back(x);
    }

    reverse(dum.begin(),dum.end());

    // de(dum);

    for(int i=0;i<dum.size();i++) {
        if(i==dum.size()-1){
            if(dum[i]<ans){
                cnt++;
                prnt=ans+dum[i];
            }
        }
        else if(dum[i+1]+ans>dum[i]) {
            prnt = ans + dum[i] + dum[i+1];
            cnt+=2;
            break;
        }
    }
    if(cnt>2) {
        cout<<prnt;
    }
    else {
        cout<<0;
    }
    return;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}