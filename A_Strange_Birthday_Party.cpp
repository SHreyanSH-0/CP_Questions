#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    long long k,c;
    cin>>k>>c;
    vector<long long> vk(k), vc(c);

    for (long long i = 0; i < k; i++)
    {
        cin>>vk[i];
        vk[i]--;
    }
    for (long long i = 0; i < c; i++)
    {
        cin>>vc[i];
    }    

    sort(vk.begin(),vk.end());
    int j = 0;
    long long ans = 0;
    for (int i = vk.size()-1; i >=0; i--)
    {
        if(j<vk[i]){
            ans += vc[j];
            j++;
        }
        else{
            ans+=vc[vk[i]];
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
