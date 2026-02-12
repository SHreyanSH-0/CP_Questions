#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

double rock(double r, double s, double p, vector<vector<vector<double>>>& dp){
    if(r<=0||s<0||p<0) return 0;

    if(s==0&&p==0) return 1;
    
    if(dp[r][s][p]!=-1) return dp[r][s][p];
    
    double sum = r*p + p*s + r*s, a=0,b=0,c=0;
    
    if(r>0)
    a = rock(r-1,s,p,dp)*(r*p/sum);
    if(s>0)
    b = rock(r,s-1,p,dp)*(r*s/sum);
    if(p>0)
    c = rock(r,s,p-1,dp)*(s*p/sum);
    
    // cout<<a<<" "<<b<<" "<<c<<endl;
    
    return dp[r][s][p] = (a + b + c);
}
double paper(double r, double s, double p, vector<vector<vector<double>>>& dp){
    if(p<=0||s<0||r<0) return 0;

    if(s==0&&r==0) return 1;
    
    if(dp[r][s][p]!=-1) return dp[r][s][p];
    
    double sum = r*p + p*s + r*s, a=0,b=0,c=0;
    
    if(r>0)
    a = paper(r-1,s,p,dp)*(r*p/sum);
    if(s>0)
    b = paper(r,s-1,p,dp)*(r*s/sum);
    if(p>0)
    c = paper(r,s,p-1,dp)*(s*p/sum);
    
    // cout<<a<<" "<<b<<" "<<c<<endl;
    
    return dp[r][s][p] = (a + b + c);
}
double sci(double r, double s, double p, vector<vector<vector<double>>>& dp){
    if(s<=0||r<0||p<0) return 0;

    if(r==0&&p==0) return 1;
    
    if(dp[r][s][p]!=-1) return dp[r][s][p];
    
    double sum = r*p + p*s + r*s, a=0,b=0,c=0;
    
    if(r>0)
    a = sci(r-1,s,p,dp)*(r*p/sum);
    if(s>0)
    b = sci(r,s-1,p,dp)*(r*s/sum);
    if(p>0)
    c = sci(r,s,p-1,dp)*(s*p/sum);
    
    // cout<<a<<" "<<b<<" "<<c<<endl;
    
    return dp[r][s][p] = (a + b + c);
}

void solve()
{
    double r,s,p;

    cin>>r>>s>>p;
    vector<vector<vector<double>>> dp(r+1,vector<vector<double>>(s+1,vector<double>(p+1,-1)));
    vector<vector<vector<double>>> dp2(r+1,vector<vector<double>>(s+1,vector<double>(p+1,-1)));
    vector<vector<vector<double>>> dp3(r+1,vector<vector<double>>(s+1,vector<double>(p+1,-1)));

    cout<<fixed<<setprecision(12)<<rock(r,s,p,dp)<<" "<<sci(r,s,p,dp3)<<" "<<paper(r,s,p,dp2)<<endl;
}
int main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
