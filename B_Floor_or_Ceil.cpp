#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    long long  x,n,m;
    cin>>x>>n>>m;
    long long min = x, max = x;
    long long n1 = n, m1 = m;
    for (int i = 0; i < m1&&min>1; i++)
    {
        if(min%2==0) min = min/2;
        else min = min/2 + 1;
    }

    for (int i = 0; i < n1&&min>0; i++)
    {
        min = min/2;
    }
    
    n1 = n;
    m1 = m;

    for (int i = 0; i < n1&&max>0; i++)
    {
       max =max/2;
    }
    for (int i = 0; i < m1&&max>1; i++)
    {
        if(max%2==0)max =max/2;
        else max =max/2 + 1;
    }
    

    cout<<min<<" "<<max<<endl;
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