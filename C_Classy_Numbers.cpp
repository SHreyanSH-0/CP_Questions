#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define int long long

int dp[20][2][20];

long long solve(string &s, int i, int count, int tight)
{
    if(i==s.size()) return count <= 3;

    if(dp[i][tight][count]!=-1) return dp[i][tight][count];

    int limit = (tight==1? s[i]-'0':9);

    int ans = 0;

    for (int ind = 0; ind <= limit; ind++)
    {
        int c = count + (ind!=0);
        ans += solve(s,i+1,c,(tight&&(s[i]-'0'== ind)));

    }
    return dp[i][tight][count] = ans;
    
    
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        long long l , r;
        cin >> l>>r;
        string s1 , s2 ;
        s1 = to_string(l-1);
        s2 = to_string(r);
        memset(dp,-1,sizeof(dp));
        int start = solve(s2,0,0,1);
        memset(dp,-1,sizeof(dp));
        int end = solve(s1,0,0,1);
        cout<< start-end <<endl;
    }
    return 0;
}
