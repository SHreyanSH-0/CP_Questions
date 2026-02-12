#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 998244353

int dp[19][2][10][1024][2];
vector<int> kp;
int fact(int n){
    int ans =1 ;
    for(int i=1;i<=n;i++){
        ans = ans * i;
    }
    return ans;
}

int ncr(int n,int r){
    int hold = fact(n)/(fact(r)*fact(n-r));
    // cout<<n<<"C"<<r<<"="<<hold<<endl;
    return hold%mod;
}
int fun(int n, int p){
    int ans = 1;
    for(int i=0;i<p;i++) ans = (ans*n)%mod;
    return ans;
}

int rec(string &s, int i, int tight, int diff, int bit, int started, int k){
    if(i>=s.size()) return 0;

    // if(dp[i][tight][diff][bit][started]!=-1) return dp[i][tight][diff][bit][started];
    int l = (tight == 1)? s[i]-'0': 9;
    int ans = 0;
    int p = (ll)pow(10,s.size()-i-1)%mod;
    for(int ind = 0;ind<=l; ind++){
        if(!started&&ind==0){
            ans += rec(s,i+1,tight&&ind==l,diff,bit,0,k);
            ans %= mod;
            continue;
        }

        int hold = (1<<ind);
        int ct = 0;
        if((bit&hold)==0) ct = 1;

        if(ct+diff<=k){
            int h;
            // if(tight ==0||ind!=l) 
            h = (ind*kp[s.size()-i-1]*p*ncr(10-diff - ct,k-(diff+ct)) + rec(s,i+1,tight&&ind==l,diff+ct,(bit|hold),1,k))%mod;
            // else h =  rec(s,i+1,tight&&ind==l,diff+ct,(bit|hold),1,k);
            ans += h;
        }
        // cout<<ans<<endl;

    }
    return dp[i][tight][diff][bit][started] = ans;
}

void solve()
{
    int l,r,k;
    cin>>l>>r>>k;
    int hold = 1;
    for (int i = 0; i <= 18; i++)
    {
        kp.push_back(hold);
        hold = (hold*k)%mod;
    }
    
    string a = to_string(l-1);
    string b = to_string(r);
    memset(dp,-1,sizeof(dp));
    int hold1 = rec(a,0,1,0,0,0,k);
    memset(dp,-1,sizeof(dp));
    int hold2 = rec(b,0,1,0,0,0,k);
    cout<<hold1<<" "<<hold2<<endl;
    cout<<(hold2 - hold1 + mod)%mod<<endl;
}
signed main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
