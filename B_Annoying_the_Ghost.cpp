#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    vector<int> sorted = a;
    sort(sorted.begin(),sorted.end());

    for (int i = 0; i < n; i++)
    {
        if(sorted[i]>b[i]){
            cout<<-1<<endl;
            return;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==b[i]) continue;
        int ind = -1;
        for(int j=i;j<n;j++){
            if(a[j]<=b[i]){
                ind = j;
                break;
            }
        }

        for(int j=ind;j>i;j--){
            swap(a[j],a[j-1]);
            ans++;
        }
    }
    cout<<ans<<endl;
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
