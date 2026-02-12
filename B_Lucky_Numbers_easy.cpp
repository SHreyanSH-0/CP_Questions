#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int rec(int four, int seven, int num,int n){
    if(four==0&&seven==0){
        return num>=n?num:1e15;
    }
    else if(four<0||seven<0){
        return 1e18
        ;
    }

    int hold;
    int a = rec(four-1, seven,num*10 + 4,n);
    int b = rec(four, seven-1,num*10 + 7,n);
    hold = min(a,b);
    return hold;
}

void solve()
{
    int n ;
    cin>>n;

    int hold = n;
    int digit = 0;
    while(hold>0){
        digit++;
        hold/=10;        
    }

    if(digit%2==1){
        digit++;
        for(int i=0;i<digit/2;i++){
            cout<<4;
        }
        for(int i=0;i<digit/2;i++){
            cout<<7;
        }
        return;

    }
    else{
        int high = 0, low = 0;

        for(int i=0;i<digit/2;i++){
            high = high*10 + 7;
            low = low*10 + 4;
        }
        for(int i=0;i<digit/2;i++){
            high = high*10 + 4;
            low = low*10 + 7;
        }

        if(n>high){
            digit+=2;
            for(int i=0;i<digit/2;i++){
                cout<<4;
            }
            for(int i=0;i<digit/2;i++){
                cout<<7;
            }
            return;
        }
        else{
            cout<<rec(digit/2,digit/2,0,n);
        }
    }

}
signed main() {

    int test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
