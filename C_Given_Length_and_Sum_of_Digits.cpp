#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int m, s;
    cin>>m>>s;
    int nine = s/9;

    if((s==0&&m>1)||nine>m||s>9*m){
        cout<<"-1 -1\n";
    }
    else if(nine==m){
        for (int i = 0; i < m; i++)
        {
            cout<<9;
        }cout<<" ";
        for (int i = 0; i < m; i++)
        {
            cout<<9;
        }cout<<endl;
        
    }
    else{
        int hold = s%9;

        vector<char> low(m),high(m);
        
        if(hold==0&&nine>0){
            nine--;
            for(int i=0;i<nine;i++){
                low[m-i-1] = '9';
            }

            low[m-nine-1] = '8';
            for(int i=m-nine-2;i>0;i--){
                low[i] = '0';
            }
            low[0] = '1';
        }
        else{
            for(int i=0;i<nine;i++){
                low[m-i-1] = '9';
            }
            if(m-nine>=2){
                hold = s%9-1;
                low[0] = '1';
                low[m-nine-1] =hold + '0'; 
                for(int i=m-nine-2;i>0;i--){
                    low[i] = '0';
                }
            }
            else{
                hold = s%9;
                low[0] = hold + '0';
                for(int i=m-nine-1;i>0;i--){
                    low[i] = '0';
                }
            }
        }

        
        hold = s%9;
        nine = s/9;
        for(int i=0;i<nine;i++){
            high[i] = '9';
        }
        high[nine] = hold + '0';
        for (int i = nine+1; i < m; i++)
        {
            high[i] = '0';
        }

        
        for (int i = 0; i < m; i++)
        {
            cout<<low[i];
        }
        cout<<" ";
        for (int i = 0; i < m; i++)
        {
            cout<<high[i];
            /* code */
        }
        cout<<"\n";

    }
}
int main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
