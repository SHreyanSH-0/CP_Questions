#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int base1 = 31, base2 = 57;
int power(long long a,long long b){
    long long ans = 1;

    while(b>0){
        if(b%2==1) ans = (ans*a)%mod;
        a = (a*a)%(mod);
        b/=2;
    }
    return ans;
}
bool isPal(int start, int end, vector<int>&pref1, vector<int>&pref2,vector<int>&pref3, vector<int>&pref4,vector<int>&inv31,vector<int>&inv37){
    int l = (end - start + 1);
    int hold1, hold2;
    int hash1, hash2;
    int n = pref1.size();
    if(l%2==1){
        int l = start, r = end;
        int mid = (l+r)/2;
        if(start==0){
            hold1 = pref1[mid-1];
            hold2 = pref2[mid-1]; 
            hash1 = (hold1<<32)|hold2;

            hold1 = (((pref3[mid+1] - pref3[r+1]+mod)%mod)*inv31[n-1-r])%mod;
            hold2 = (((pref4[mid+1] - pref4[r + 1]+mod)%mod)*inv37[n-1-r])%mod; 
            hash2 = (hold1<<32)|hold2;
        }
        else{
            hold1 = (((pref1[mid-1] - pref1[l-1]+ mod)%mod)*inv31[l])%mod;
            hold2 = (((pref2[mid-1] -pref2[l-1]+ mod)%mod)*inv37[l])%mod; 
            hash1 = (hold1<<32)|hold2;

            hold1 = (((pref3[mid+1] - pref3[r+1]+ mod)%mod)*inv31[n-1-r])%mod;
            hold2 = (((pref4[mid+1] - pref4[r+1]+ mod)%mod)*inv37[n-1-r])%mod; 
            hash2 = (hold1<<32)|hold2;
        }
    }
    else{
        int l = start, r = end;
        int mid = (l+r)/2;
        if(start==0){
            mid++;
            hold1 = pref1[mid-1];
            hold2 = pref2[mid-1]; 
            hash1 = (hold1<<32)|hold2;

            hold1 = (((pref3[mid] - pref3[r+1] + mod)%mod)*inv31[n-1-r])%mod;
            hold2 = (((pref4[mid] - pref4[r+1]+ mod)%mod)*inv37[n-1-r])%mod; 
            hash2 = (hold1<<32)|hold2;
        }
        else{
            mid++;
            hold1 = (((pref1[mid-1] - pref1[l-1]+ mod)%mod)*inv31[l])%mod;
            hold2 = (((pref2[mid-1] -pref2[l-1]+ mod)%mod)*inv37[l])%mod; 
            hash1 = (hold1<<32)|hold2;
            hold1 = (((pref3[mid] - pref3[r+1]+ mod)%mod)*inv31[n-1-r])%mod;
            hold2 = (((pref4[mid] - pref4[r+1]+ mod)%mod)*inv37[n-1-r])%mod; 
            hash2 = (hold1<<32)|hold2;
        }
    }

    return hash1 == hash2;
}

void solve()
{
    string s;
    string ans;
    cin>>s;
    int n = s.size();
    vector<long long> inv31(n);
    vector<long long> inv37(n);
    for(int i=0;i<n;i++){
        inv31[i] = power(power(base1,i),mod-2);
        inv37[i] = power(power(base2,i),mod-2);
    }
    int hash1 = 0,hash2 = 0, p1 =1,p2=1;
    vector<int> pref1(n), pref2(n),pref3(n+1,0),pref4(n+1,0);
    for(int i=0;i<n;i++){
        hash1 = (hash1 + (p1*s[i])%mod)%mod;
        hash2 = (hash2 + (p2*s[i])%mod)%mod;
        p1 = (p1*base1)%mod;
        p2 = (p2*base2)%mod;
        pref1[i] = hash1;
        pref2[i] = hash2;
    }
    hash1 = 0,hash2 = 0, p1 =1,p2=1;

    for(int i=n-1;i>=0;i--){
        hash1 = (hash1 + (p1*s[i])%mod)%mod;
        hash2 = (hash2 + (p2*s[i])%mod)%mod;
        p1 = (p1*base1)%mod;
        p2 = (p2*base2)%mod;
        pref3[i] = hash1;
        pref4[i] = hash2;
    }

    int l = 0, r = n - 1;
    while(l<r){
        if(s[l]==s[r]){
            l++;
            r--;
        }
        else{
            break;
        }
    }
    int hold1 = l-1, hold2 = r + 1;
    for (int i = l; i <= r; i++)
    {
        int start = l;
        int end = i;

        int length = (end - start + 1);

        if(length==1) {
            hold1 = i;
            continue;
        }

        if(isPal(start,end,pref1,pref2,pref3,pref4,inv31,inv37)){
            hold1 = i;
        }
    }

    for (int i = r; i>=l; i--)
    {
        int start = i;
        int end = r;

        int length = (end - start + 1);

        if(length==1) {
            hold2 = i;
            continue;
        }
        if(isPal(start,end,pref1,pref2,pref3,pref4,inv31,inv37)){
            hold2 = i;
        }
    }

    int len1 = hold1 + 1 + (n-1 - r);
    int len2 = (n- hold2) + (l);

    if(len1>=len2){
        for(int i=0;i<=hold1;i++){
            ans.push_back(s[i]);
        }
        for(int i=r+1;i<n;i++){
            ans.push_back(s[i]);
        }
    }
    else{
        for(int i=0;i<l;i++){
            ans.push_back(s[i]);
        }
        for(int i=hold2;i<n;i++){
            ans.push_back(s[i]);
        }
    }    
    if(ans=="") cout<<s[0]<<endl;
    else cout<<ans<<endl;
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
