#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int a , b;
    cin>>a>>b;
    int start = 0;
    if(b==1){
        b++;
        start = 1;
    }
    int x = ceil(log2(a));

    int ans = INT_MAX;
    for(int i=0;i<=x;i++){
        int bHold = b;
        bHold += i;
        int count = start + i;
        int hold = a;
        while(hold>0){
            hold/=bHold;
            count++;
        }
        
        ans = min(ans,count);
        count = 0;
    }

    cout<<ans<<endl;
    
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
