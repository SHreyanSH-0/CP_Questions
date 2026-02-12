#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

long long rangeBitwiseAnd(long long  left, long long right)
{
    long long ans = 0;
    long long hold = right - left;
    long long gap = 1;
    while (left > 0)
    {
        if (left % 2 == 1 && right % 2 == 1)
        {
            if (hold < gap)
            {
                ans += gap;
            }
        }
        left /= 2;
        right /= 2;
        gap *= 2;
    }
    return ans;
}


void solve()
{
    long long n, x, pow = 1, ans = 0;
    cin >> n >> x;

    if (x > n)
    {
        cout << -1 << endl;
    }
    else if (x == n)
    {
        cout << x << endl;
    }
    else if(x==0){
        int d = log2(n) +1;
        long long ans = (ll)1<<d;
        cout<<ans<<endl;
    }
    else
    {
        long long hold = n, hold2 = x;
        bool check = true;
        long long plus = 0;
        while(n>0){
            if(x%2==1&&n%2==1){
                ans += pow;
            }
            else if(x%2==0&&n%2==0&&check){
                check = false;
                plus = pow;
            }
            else if(x%2==0&&n%2==1){
                check = true;
                plus = pow*2;
            }
            else if(x%2==1&&n%2==0){
                ans = -1;
                break;
            }
            pow*=2;
            x/=2;
            n/=2;
        }
        ans|=plus;
        
        if(ans!=-1&&ans>hold&&rangeBitwiseAnd(hold,ans)==hold2)
        cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}
int main()
{

    ll test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
