#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int check = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(i>0&&v[i]==v[i-1])
            check++;
    }

    if(check == n-1)
        cout<<0<<endl;
    else{
        int val = v[n-1];
        int ans = 0;
        int count = 0;
        for (int i = n-1; i>=0;){
            
            while(i>=0&&(v[i]==val)) {
                i--;
                count++;
            }
            if(i>=0)
            ans++;
            i-=count;
            count *=2;

        }

        cout<<ans<<endl;

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
