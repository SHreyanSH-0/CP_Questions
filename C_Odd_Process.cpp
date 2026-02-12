#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define yes cout << "YES\n"
#define yes cout << "NO\n"
#define nl cout << endl
typedef vector<int> vi;
typedef vector<ll> vll;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>odd;
    vector<int>even;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2!=0){
            odd.push_back(a[i]);
        }
        else{
            even.push_back(a[i]);
        }
    }
    sort(even.begin(),even.end(),greater<int>());
    sort(odd.begin(),odd.end(),greater<int>());
    if(odd.size()==0){
        for(int i=0;i<n;i++){
            cout<<"0"<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<odd[0]<<" ";
        int sum=odd[0];
        for(int i=0;i<even.size();i++){
            sum+=even[i];
            cout<<sum<<" ";
        }
        int val1;
        if(even.size()==0){
            val1=0;
        }
        else{
            val1=sum-even[even.size()-1];
        }
        int val2=sum;
        for(int i=1;i<odd.size()-1;i++){
            if(i%2==1){
                cout<<val1<<" ";
            }
            else{
                cout<<val2<<" ";
            }
        }
        if(odd.size()%2==0){
            cout<<0<<endl;
        }
        else{
            if(odd.size()==1){
                cout<<endl;
            }
            else{
                cout<<sum<<endl;
            }
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t;
    while(t--){
        solve();
    }   
}