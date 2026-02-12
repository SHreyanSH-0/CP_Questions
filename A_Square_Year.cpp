#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
        cin>>s;

        int num = (s[3]-48) +(s[2]-48)*10 +(s[1]-48)*100 +(s[0]-48)*1000;
        int check = 1;
        for(int i=0;i<=num&&check;i++){
            for (int j = 0; i <= num; i++)
            {
                if((i+j)*(i+j)==num){
                    cout<<i<<" "<<j<<endl;
                    check = 0;
                    break;
                }

            }
            
        }
        if(check)
        cout<<-1<<endl;
}
int main(){
    
}
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
