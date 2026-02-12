// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod 1000000007
// void solve()
// {
//     int n,x;
//     cin>>n>>x;

//     vector<int> v(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin>>v[i];
//     }
//     int a = 0, b = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if(v[i]==1){
//             a = i;
//             break;
//         }
//     }

//     for (int i = n-1; i >=0; i--)
//     {
//         if(v[i]==1){
//             b = i;
//             break;
//         }

//     }

//     if(b-a+1<=x){
//         cout<<"YES\n";
//     }
//     else cout<<"NO\n";
    
    
    

// }
// int main() {

//     ll test=1;
// cin>>test;
//     while(test--)
//     {
//         solve();
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);

        for(int j=0; j<n;j++){
            cin>>a[j];
        }
        int start = 0, end = n-1;
        while(a[start]==0){
            start++;
        }
        while(a[end]==0){
            end--;
        }
        int x = end-start+1;
        if(k>=x) cout<<"YES\n";
        else cout<<"NO\n";
    }
}