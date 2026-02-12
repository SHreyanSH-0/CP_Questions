#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    sort(b.begin(),b.end());
    int z = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        if(b[i] ==0){
            z++;
        }
        else{
            sum += b[i];
        }
    }
    int largest = b[n-1];
    int hold= n - z;
    int ans = 0;
    for(int i=1;i<=hold;i++){
        int h = sum - i;

        if(h>=n-1){
            ans = i;
        }
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
