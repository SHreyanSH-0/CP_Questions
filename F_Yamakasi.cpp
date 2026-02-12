#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    long long n,s,x;
    cin>>n>>s>>x;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    long long ans = 0;

    for (int i = 0; i < n; i++){
        if(v[i]>x){
            continue;;
        }
        bool check = false;
        long long sum = 0;
        for(int j=i;j<n;j++){
            sum+=v[j];
            if(v[j]==x) check = true;
            else if(v[j]>x){
                break;
            }
            if(sum==s&&check) ans++;
        }
    }

    cout<<ans<<endl;
}
int main() {

    ll test=1;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}
