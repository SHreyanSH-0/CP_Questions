#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string a,b;
    cin>>n>>a>>b;
    int c = 0;
    int one = 0, zero = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]) {c++;
            if(a[i]=='1') one++;
            else zero++;
        }
    }
    if(a==b) cout<<"YES"<<endl;
    else if(c%2==1||one!=zero) cout<<"NO"<<endl;
    else{
        int ans = 1;
        zero = 0, one = 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]=='1') one++;
            else zero++;
            
            if(a[i]!=b[i]){
                
                if(a[i]=='1') one--;
                else zero--;
                if(one!=zero){
                    ans = 0;
                    break;
                }
                else{
                    while (i<n&&a[i]!=b[i])
                    {
                        if(a[i]=='1') one++;
                        else zero++;
                        i++;
                    }i--;
                    if(one!=zero) {
                        ans = 0;
                        break;
                    }
                }
            }
        }
        
        
        if(ans) 
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
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
