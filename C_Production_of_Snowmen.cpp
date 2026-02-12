#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }
    
    int ans = 0;
    set<int> s,s2;
    for (int i = 0; i < n; i++)
    {
        bool check = true;
        for (int j = 0; j < n; j++)
        {
            if(a[j]>=b[(j+i)%n]){
                check = false;
                break;
            }            
        }
        if(check){
            s.insert(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool check = true;
        for (int j = 0; j < n; j++)
        {
            if(b[j]>=c[(j+i)%n]){
                check = false;
                break;
            }            
        }
        if(check){
            s2.insert(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c1 = (i+j)%n;
            if(s.find(i)!=s.end()&&s2.find(c1)!=s2.end()) ans+=n;
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
