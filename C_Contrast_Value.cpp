#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int c = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(i>0&&v[i]==v[i-1]){
            c++;
        }
    }

    if(c==n-1) {
        cout<<1<<endl;
        return;
    }
    int ans = 1;
    for(int i = 0; i < n-1;) {
        if(v[i]<v[i+1]){
            while (i<n-1&&v[i]<=v[i+1]){
                i++;
            }
            ans++;
        }
        else if(v[i]>v[i+1]){
            while (i<n-1&&v[i]>=v[i+1]){
                i++;
            }
            ans++;
        }
        else {
            i++;
        }
    }
    cout<<ans<<endl;
}
int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
