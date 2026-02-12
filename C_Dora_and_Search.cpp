#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int min = 1, max = n;
    int l = 0, r = n-1;
    while(r-l>2){
        if(v[l]==min){
            min++;
            l++;
        }
        else if(v[l]==max){
            max--;
            l++;
        }
        else if(v[r]==min){
            min++;
            r--;
        }
        else if(v[r]==max){
            r--;
            max--;
        }
        else{
            cout<<l+1<<" "<<r+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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
