#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    long long mod =998244353;

    int n;
    cin>>n;
    vector<long long> a(n),b(n),A(n),B(n),p(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    p[0] = 1;
    for (int i = 1; i < n; i++)
    {
        p[i] = (p[i-1]*2)%mod;
    }
    
    
    long long Ma,Mb;
    Ma = INT_MIN;
    Mb = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if(a[i]>Ma){
            A[i] = i;
            Ma = a[i];
        }
        else A[i] = A[i-1];
        
        if(b[i]>Mb){
            B[i] = i;
            Mb = b[i];
        }
        else B[i] = B[i-1];
    }
    for (int i = 0; i < n; i++)
    {
        long long r;
        if(a[A[i]]>b[B[i]]){
            r = (p[a[A[i]]]+p[b[i-A[i]]])%mod;
        }
        else if(a[A[i]]<b[B[i]]){
            r = (p[a[i-B[i]]]+p[b[B[i]]])%mod;
        }
        else{
            if(a[i-B[i]]>b[i-A[i]]){
                r = (p[a[i-B[i]]]+p[b[B[i]]])%mod;
            }
            else{
                r = (p[a[A[i]]]+p[b[i-A[i]]])%mod;
            }
        }
        cout<<r<<" ";
    }cout<<endl;
    
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
