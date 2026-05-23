#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int dp[19][2];

int rec(string&s,vector<int>&v,int i,int n,int carry){
    if(i>=n) {
        if(carry==1){
            return LLONG_MAX;
        }
        return 0;
    }
    if(dp[i][carry]!=-1) return dp[i][carry];
    int aval = s[i] - '0';
    int nc = 0;
    if(carry==1) {
        if(aval==0){
            aval = 9;
            nc = 1;
        } 
        else aval--;
    }
    int ans = LLONG_MAX;
    for(int j=0;j<v.size();j++){
        int newCarry = nc;
        int hold = aval;
        if(aval - v[j]<0){
            hold += 10;
            newCarry = 1;
        }
        int sub =  rec(s,v,i+1,n,newCarry);
        if(sub>= LLONG_MAX/10) continue;
        ans = min(ans,(hold - v[j]) +sub*10);
    }
    return dp[i][carry] = ans;
}
int rec4(string&s,vector<int>&v,int i,int n,int carry){
    if(i>=n) {
        if(carry==1){
            return (s[s.size()-1] - '0') - 1;
        }
        return s[s.size()-1] - '0';
    }
    if(dp[i][carry]!=-1) return dp[i][carry];
    int aval = s[i] - '0';
    int nc = 0;
    if(carry==1) {
        if(aval==0){
            aval = 9;
            nc = 1;
        } 
        else aval--;
    }
    int ans = LLONG_MAX;
    for(int j=0;j<v.size();j++){
        int newCarry = nc;
        int hold = aval;
        if(aval - v[j]<0){
            hold += 10;
            newCarry = 1;
        }
        int sub =  rec4(s,v,i+1,n,newCarry);
        if(sub >= LLONG_MAX/10) continue;
        int hold1 = (hold - v[j]) + sub*10;
        ans = min(ans,hold1);
    }
    return dp[i][carry]=ans;
}
int rec2(string&s,vector<int>&v,int i,int n,int carry){
    if(i>=n) {
        if(carry==1){
            return LLONG_MAX;
        }
        return 0;
    }
    if(dp[i][carry]!=-1) return dp[i][carry];
    int aval = s[i] - '0';
    int ans = LLONG_MAX;
    for(int j=0;j<v.size();j++){
        int newCarry = 0;
        int val = v[j];
        if(carry==1){
            if(val == 0){
                val = 9;
                newCarry = 1;
            } 
            else val--;
        }
        
        if(val - aval < 0){
            val += 10;
            newCarry = 1;
        }
        int sub =  rec2(s,v,i+1,n,newCarry);
        if(sub >= LLONG_MAX/10) continue;
        ans = min(ans,(-aval + val) + sub*10);
    }
    return dp[i][carry]=ans;
}
int rec3(string&s,vector<int>&v,int i,int n,int carry){
    if(i>=n-1) {
        if(carry==1){
            if(v[0]==0) return v[1] - 1;
            else return v[0] - 1;
        }
        return v[0]==0?v[1]:v[0];
    }
    if(dp[i][carry]!=-1) return dp[i][carry];
    int aval = s[i] - '0';
    int ans = LLONG_MAX;
    for(int j=0;j<v.size();j++){
        int newCarry = 0;
        int val = v[j];
        if(carry==1){
            if(val == 0){
                val = 9;
                newCarry = 1;
            } 
            else val--;
        }
        
        if(val - aval < 0){
            val += 10;
            newCarry = 1;
        }
        int sub =  rec3(s,v,i+1,n,newCarry);
        if(sub >= LLONG_MAX/10) continue;
        ans = min(ans,(-aval + val) + sub*10);
    }
    return dp[i][carry]=ans;
}

void solve()
{
    int a,n;
    cin>>a>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    if(n==1&&v[0]==0){
        cout<<a<<endl;
        return;
    }

    string s = to_string(a);
    int d = s.size();
    reverse(s.begin(),s.end());
    memset(dp,-1,sizeof(dp));
    int ans = rec(s,v,0,d,0);
    memset(dp,-1,sizeof(dp));
    ans = min(ans,rec2(s,v,0,d,0));
    memset(dp,-1,sizeof(dp));
    ans = min(ans,rec3(s,v,0,d+1,0));
    memset(dp,-1,sizeof(dp));
    if(d>=2)
    ans = min(ans,rec4(s,v,0,d-1,0));

    if(v[0]==0) ans = min(ans,a);

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
