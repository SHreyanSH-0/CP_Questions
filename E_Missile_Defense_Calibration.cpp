#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int xmax=1e17;
    int xmin = 0;
    int prev = -1;
    for (int i = 1; i < n; i++)
    {        
        if(v[i]<v[i-1]){
            if(i==prev+1) {
                cout<<"NO"<<endl;
                return;
            }
            if(xmax==1e17){
                xmax = (-v[i] + v[i-1]);
                xmin = xmax;
                if(i+1<n){
                    xmax = max(xmax,(-v[i] + v[i+1]));
                }
            } 
            else{
                int a = (-v[i] + v[i-1]);
                int newmin = a;
                if(i+1<n){
                    a = max(a,(-v[i] + v[i+1]));
                }
                xmax = min(xmax,a);
                xmin = max(xmin,newmin);
                if(xmin>xmax){
                    cout<<"No"<<endl;
                    return;
                }
            }
            prev = i;
        }
    }

    for(int i=1;i<n;i++){
        if(v[i]<v[i-1]) v[i] += xmax;
    }
    for(int i=1;i<n;i++){
        if(v[i]<v[i-1]){
            v[i]+=xmax;
        }
    }
    // cout<<endl;

    cout<<"Yes"<<endl;
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
