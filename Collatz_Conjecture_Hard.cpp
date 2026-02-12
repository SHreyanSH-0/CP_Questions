#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    if(n==1) {cout<<0<<endl; return;}
    if(n%2==0&&(n/2)%2==0){
        int hold = n;
        int steps = 0;
        while (hold%2==0)
        {
            steps++;
            hold/=2;
        }

        while(hold>0){
            if(hold==1) break;
            else if(hold==3){
                steps++;
                break;
            }

            if(hold%2==1){
                steps+=2;
                hold++;
                hold/=2;
            }
            else{
                steps++;
                hold/=2;
            }
        }

        cout<<steps<<endl;
        
                
    }
    else if(n%2==0&&(n/2)%2==1){
        n = n/2;
        if(n==1){
            cout<<1<<endl;
            return;
        }
        if(n==3){
            cout<<2<<endl;
        }
        else cout<<-1<<endl;
        return;
    }
    else{
        if(n==3){
            cout<<1<<endl;
        }
        else cout<<-1<<endl;
        return;
    }
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
