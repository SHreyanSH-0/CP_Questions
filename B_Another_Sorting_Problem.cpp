// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define ll long long
// #define mod 1000000007

// void solve()
// {
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++) cin>>v[i];

//     long long xmin = 0;
//     long long xmax = 4e18;
//     int prev = -5;

//     for(int i=1;i<n;i++){
//         if(v[i] < v[i-1]){
//             if(i == prev + 1){
//                 cout<<"No\n";
//                 return;
//             }

//             long long L = v[i-1] - v[i];
//             long long R = 4e18;
//             if(i+1 < n) R = v[i+1] - v[i];

//             xmin = max(xmin, L);
//             xmax = min(xmax, R);

//             if(xmin > xmax){
//                 cout<<"No\n";
//                 return;
//             }

//             prev = i;
//         }
//     }

//     for(int i=1;i<n;i++){
//         if(v[i] < v[i-1]){
//             v[i] += xmin;
//         }
//     }

//     for(int i=1;i<n;i++){
//         if(v[i] < v[i-1]){
//             cout<<"No\n";
//             return;
//         }
//     }

//     cout<<"Yes\n";
// }

// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     ll test;
//     cin>>test;
//     while(test--) solve();
// }
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
    int mini = -1e9, maxi = -1e9;
    for (int i = 1; i < n; i++)
    {        
        if(v[i]<v[i-1]){
            mini = max(mini,v[i-1] - v[i]);
        }
    }
    // cout<<mini<<endl;
    if(mini==-1e9){
        cout<<"YES"<<endl;
        return;
    }
    // cout<<v[0]<<" ";
    for(int i=1;i<n;i++){
        if(v[i]<v[i-1]) v[i] += mini;
        // cout<<v[i]<<" ";
    }
    // cout<<endl;
    for(int i=1;i<n;i++){
        if(v[i]<v[i-1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    // cout<<endl;

    cout<<"YES"<<endl;
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