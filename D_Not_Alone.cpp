#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int rec(vector<int>&v, int i,vector<int> &dp){
    if(i>=v.size()){
        for(int ind=0;ind<v.size();ind++){
            int right = ind+1<v.size()?ind+1:0;
            int left = ind-1>=0?ind-1:v.size()-1;

            if(v[ind]!=v[left]&&v[ind]!=v[right]) return 1e8;
        }
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    
    int right = i+1<v.size()?i+1:0;
    int left = i-1>=0?i-1:v.size()-1;

    int a , b , c;
    a = b = c = INT_MAX;
    
    int hold = v[i];
    v[i] = v[left];
    a = abs (hold - v[left]) + rec(v,i+1,dp);

    v[i] = v[right];
    b = abs (hold - v[right]) + rec(v,i+1,dp);
    v[i]=hold;
    
    c = rec(v,i+1,dp);
    
    return dp[i] = min(a,min(b,c));
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> dp(n,-1);
    cout<<rec(v,0,dp)<<endl;

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
