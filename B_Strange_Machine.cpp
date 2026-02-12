#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;


    while(q--){
        int a;
        cin>>a;
        int ans = 0;
        int i= 0;
        int acount = 0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='A'){
                acount++;
            }
            else break;
        }

        if(acount==n){
            cout<<a<<endl;
        }
        else{

            while (a>0)
            {
                if(s[i]=='A'){
                    a = a - 1;
                }
                else{
                    a = a/2;
                }
                
                i = (i+1)%n;
                ans++;
            }
            cout<<ans<<endl;
        }        
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
