#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    
    if(n%2==1){
        cout<<n<<endl;
        for(int i=2;i<n-1;i++){
            cout<<i<<" ";
        }
        cout<<1<<" "<<n-1<<" "<<n<<endl;
    }
    else{
        int max = INT_MIN;
        int val;

        for(int i=2;i<=n-1;i++){
            int hold = (n|i);
            if( hold > max){
                max = hold;
                val = i;
            }
        }
        
        cout<<max<<endl;

        if(val==n-1){
            for(int i=2;i<n-2;i++){
                cout<<i<<" ";
            }
            cout<<1<<" "<<n-2<<" "<<n-1<<" "<<n<<endl;

        }
        else{
            for(int i=2;i<=n-1;i++){
                if(i==val||i==val-1) continue;
                cout<<i<<" ";
            }
            cout<<1<<" "<<val-1<<" "<<val<<" "<<n<<endl;

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
