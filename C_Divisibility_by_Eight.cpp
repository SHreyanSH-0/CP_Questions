#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int num=0;
        int num1 = num*10 +s[i] - '0';
        if(num1%8==0){
            cout<<"YES"<<endl;
            cout<<num1;
            return;
        }
        for (int j = i+1; j < n; j++)
        {
            int num2= num1*10 + s[j] -'0';
            if(num2%8==0){
                cout<<"YES"<<endl;
                cout<<num2;
                return ;
            }
            
            for (int k = j+1; k < n; k++)
            {
                
                int num3 = num2*10 + s[k] -'0';
                if(num3%8==0){
                    cout<<"YES"<<endl;
                    cout<<num3;
                    return ;
                }
            }
            
        }
        
    }
    cout<<"NO";
    
}
signed main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
