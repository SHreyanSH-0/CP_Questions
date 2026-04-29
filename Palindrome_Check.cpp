#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int i = 0, j = n-1;

    while(i<=j){
        if(v[i]==v[j]){
            i++;
            j--;
        }
        else{
            if(v[i]==k) i++;
            else if(v[j]==k) j--;
            else{
                cout<<"No"<<endl;
                return;
            }
        }
    }

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
