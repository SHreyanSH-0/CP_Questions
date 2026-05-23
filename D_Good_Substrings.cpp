#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
void solve()
{
    string s1,s2;
    int k;
    cin>>s1>>s2>>k;
    unordered_map<int,int> set;
    for(int i=0;i<s1.size();i++){
        int bad = 0;
        int hold = 0;
        int hold2 = 0;
        int p = 1;
        int p2 = 1;
        for(int j=i;j<s1.size();j++){
            hold = (hold + (p*(s1[j] - 'a' + 1))%mod)%mod;
            hold2 = (hold2 + (p2*(s1[j] - 'a' + 1))%mod)%mod;
            if(s2[s1[j] - 'a']=='0') bad++;
            if(bad<=k){
                set[((hold<<32)|hold2)]++;
            }
            else break;
            p*=31;
            p2*=37;
            p%=mod;
            p2%=mod;
        }
    }
    cout<<set.size()<<endl;

}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
