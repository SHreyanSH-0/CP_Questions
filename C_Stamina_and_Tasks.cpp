#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    cout.setf(std::ios::fixed); cout<<setprecision(10);
    while(t--){
        int n; cin>>n;
        vector<int> c(n);
        vector<int> p(n);
        for(int i=0;i<n;i++) cin>>c[i]>>p[i];
        double f = 0.0;
        for(int i=n-1;i>=0;i--){
            double r = 1.0 - p[i] / 100.0;
            f = max(f, c[i] + r * f);
        }
        cout<<f<<"\n";
    }
    return 0;
}