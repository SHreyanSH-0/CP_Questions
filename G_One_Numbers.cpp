#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007

int dp[10][2][90];

bool isPrime[101];

int rec(string &s, int i, int sum,int tight){
    if(i==s.size()){
        return isPrime[sum];
    }


    if(dp[i][tight][sum]!=-1) return dp[i][tight][sum];

    int limit = (tight==1) ? s[i] - '0' : 9;

    long long hold = 0;

    for(int ind = 0;ind<=limit;ind++){
        hold += rec(s, i+1,sum + ind, (tight) && (s[i] - '0'== ind));
    }


    return dp[i][tight][sum] = hold;
}

void solve()
{
    int r , l;
    cin>>l>>r;
    
    string start = to_string(l-1);
    string end = to_string(r);
    
    memset(dp,-1,sizeof(dp));
    int a = rec(end, 0,0, 1) ;
    memset(dp,-1,sizeof(dp));
    int b = rec(start, 0,0, 1) ;
    
    cout<<a- b<<endl;
}
signed main() {
    memset(isPrime,true,sizeof(isPrime));

    int n = 100;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
