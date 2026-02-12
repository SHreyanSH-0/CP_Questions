#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007

long long dp[20][2][20];

int rec(string& s,int i, int count,int tight,int num){
    if(i==s.size()) return count;

    if(dp[i][tight][count]!=-1) return dp[i][tight][count];

    int limit = tight==1? s[i]-'0': 9;

    long long ans = 0;

    for(int ind = 0;ind<=limit;ind++){
        long long c = count + (ind==num?1:0);
        ans += rec(s,i+1,c, tight&&(ind== s[i]-'0'),num); 
    }

    return dp[i][tight][count] = ans;
}

long long digits(long long n) {
    long long len = 0, p = 1, res = 0;
    while (p * 10 <= n) p *= 10, len++;
    while (p > 0) {
        res += (len + 1) * (n - p + 1);
        n = p - 1;
        p /= 10;
        len--;
    }
    return res;
}

void solve()
{

    int k; 
    cin>>k;

    int low = 1, high = 1e15;  
    
    while (low < high) {
        long long mid = (low + high) / 2;
        if (digits(mid) < k)
            low = mid + 1;
        else
            high = mid;
    }

    int digit = digits(low);

    int ans = 0;
    string start = to_string(low);

    for(int i=1;i<=9;i++){

        memset(dp, -1, sizeof(dp));

        int hold = rec(start,0,0,1,i);

        ans += hold*i;
    }

    if(digit<k){
        string s = to_string(low+1);
        int i= 0;
        while (i<s.size()&&digit<k)
        {
            ans+= s[i]-'0';
            i++;
            digit++;
        }
        
    }
    else if(digit>k){
        string s = to_string(low);
        int i= s.size()-1;
        while (i>=0&&digit>k)
        {
            ans-= s[i]-'0';
            i--;
            digit--;
        }
    }
    cout<<ans<<endl;
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
