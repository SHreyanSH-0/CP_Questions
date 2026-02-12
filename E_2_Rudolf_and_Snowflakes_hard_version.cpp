#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
set<int> s;
void solve()
{
    int n;
    cin>>n;


    for(int i=2;i<=64;i++){

        int high = 1e16, low = 2;
        int hold;
        while(low<=high){
            int mid = (low+high)/2;
            hold = 1;
            int last = 1;
            int j;
            for (j = 0; j < i; j++)
            {
                if(last>1e18/mid||hold > 1e18 - last*mid) break;
                last = last * mid;
                hold += last;
            }            
            if(hold==n){
                cout<<"YES"<<endl;
                return;
            }
            else if(hold>n||j<i){
                high = mid-1;
            }
            else low = mid+1;
        }
    }
    cout<<"NO"<<endl;
    
    
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
