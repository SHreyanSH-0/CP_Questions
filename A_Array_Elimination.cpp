#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> bits(32,0);

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        int hold = a[i];
        int j = 0;
        while (hold>0)
        {
            if(hold%2) bits[j]++;
            hold/=2;
            j++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        bool check = true;
        for (int j = 0; j < 32; j++)
        {
            if(bits[j]%i!=0) check = false;
        }
        if(check) cout<<i<<" ";
        
    }cout<<endl;
    


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
