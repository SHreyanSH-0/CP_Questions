#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int dp[10][101];
int f(int n){
    int ans = 1;
    for(int i= 1;i<=n;i++) ans = (ans*i)%mod;
    return ans;
}

int p(int a, int b){
    int ans = 1;
    while(b>0){
        if(b%2==1) ans =( ans * a)%mod;
        a = a*a;
        ans%=mod;
        a%=mod;
        b/=2;
    }
    return ans;
}


int rec(vector<int>&v, int i,int n,vector<int> &fact,vector<int>& inFact,int d){
    if(i>=10){
        return n==0;
    } 
    if(dp[i][n]!=-1) return dp[i][n];
    int ans = 0;
    for(int j = 0;j<=n;j++){
        int hold = (rec(v,i+1,n-j,fact,inFact,d))%mod;
        int hold1 = ((hold*inFact[j + v[i]])%mod);
        int hold2= 0;
        if(i==0){
            if(v[i] + j>0){
                hold2 = (((hold*inFact[j+v[i]-1])%mod)*fact[d-1])%mod;
                ans = (ans + (fact[d]*hold1)%mod - hold2 + mod )%mod;
            }
            else{
                ans = (ans + (fact[d]*hold1)%mod)%mod;
            }
        }
        else{
            ans = (ans + hold1)%mod;
        }
    }
    
    return dp[i][n] = ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(10);
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        cin>>v[i];
        sum+= v[i];
    }
    vector<int> fact(n+1), inFact(n+1);

    for(int i=0;i<=n;i++){
        fact[i] = f(i);
        inFact[i] = p(fact[i],mod - 2);
    }
    int ans = 0;
    for(int i=max(sum,1LL);i<=n;i++){
        memset(dp,-1,sizeof(dp));
        int hold = (rec(v,0,i - sum,fact,inFact,i))%mod;
        ans = (ans + hold)%mod;
    }
    cout<<ans<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
