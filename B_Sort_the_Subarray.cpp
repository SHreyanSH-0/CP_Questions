#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    int len=0,start = 0;
    
    for (int i = 0; i < n-1; i++)
    {
        
        int hold = 0;
        int j;
        int check = 0;
        for (j = i; j< n-1; j++)
        {
            if(b[j]<=b[j+1]){
                if(a[j]!=b[j]||a[j+1]!=b[j+1]){
                    check = 1;
                }
                hold++;
            }
            else break;

        }

        if(hold>=len&&check){
            start = i;
            len = hold;
        }

        i = j;

        
    }
    
    cout<<start+1<<" "<<start+1+len<<endl;
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
