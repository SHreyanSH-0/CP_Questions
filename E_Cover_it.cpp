#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(double mid,vector<vector<int>>&a,int &n){
    double left=-1e18;
    double right=1e18;
    for(int i=0;i<n;i++){
        double val=a[i][1]*mid;
        double temp_l=a[i][0]-val;
        double temp_r=a[i][0]+val;
        left=max(left,temp_l);
        right=min(right,temp_r);
    }
    return !(left>right);
}


// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>a[i][0];
    }
    for(int i=0;i<n;i++){
        cin>>a[i][1];
    }
    double low=0;
    double high=1e9;
    while(high-low>1e-7){
        double mid=low+(high-low)/2;
        if(check(mid,a,n)){
            high=mid;
        }
        else{
            low=mid;
        }
    }
    if(check(low,a,n)){
        cout<<setprecision(12)<<low;
    }
    else{
        cout<<setprecision(12)<<high;
    }
}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    while(_--){
        solve();
    }
}