#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    int hold = n;
    int x;
    for(int i=0;i<=hold;i++){
        if((i*(i+1))/2 < hold){
            x = i;
        }
    }
    int num1 = n , num2 = n;
    int ans = 0;
    while(x>=0){
        // cout<<num1<<" "<<num2<<endl;
        int first = (x*(x+1))/2 + 1;
        int last = ((x+2)*(x+1))/2;
        
        int left = num1 - first;
        int right = last - num1;
        if(num1==first && num2==last){
            ans += ((num2)*(1 + num2) * (2*num2 + 1))/6;
            break;
        }
        for(int i=num1;i<=num2;i++) ans += i*i;
        int hold1, hold2;
        hold2 = num2 - left - right;

        int ct = 1;
        if(hold2==first) {
            hold2--;
            ct = 0;
        }
        if(num1==first) ct = 0;
        if(num1==last) ct = 0;
        hold1 = hold2 - (num2 - num1 + ct);
        num1 = hold1;
        num2 = hold2;
        x--;
    }
    cout<<ans<<endl;


}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
