#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool prime_factorize(long long n,set<int> &s) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if(s.find(i)!=s.end()) return true;
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            s.insert(i);
        }
    }
    
    if(n>1){
        if(s.find(n)!=s.end()) return true;
        s.insert(n);
    }
    return false;
}
bool factorize(long long n,set<int> &s) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if(s.find(i)!=s.end()) return true;
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
        }
    }
    if(n>1){
        if(s.find(n)!=s.end()) return true;
    }
    return false;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n), b(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    int odd = 0, even = 0;

    sort(v.begin(),v.end());
    set<int> s;
    for (int i = 0; i < n; i++)
    {   
        if(prime_factorize(v[i],s)) {
            cout<<0<<endl;
            return;
        }
    }
    int ct = 0;

    for(int i=0;i<v.size();i++){
        if(factorize(v[i]+1,s)){
            cout<<1<<endl;
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(v[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }

    

    
    if(even>1){
        cout<<0<<endl;
    }
    else if(even ==1){
        cout<<1<<endl;
    }
    else{
        cout<<2<<endl;
    }
    
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
