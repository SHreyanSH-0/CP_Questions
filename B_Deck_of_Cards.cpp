#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    string s;
    cin>>n>>k>>s;

    if(n==k){
        for (int i = 0; i < n; i++)
        {
            cout<<'-';
        }
        
    }
    else{
        int zeros = 0, one = 0, two = 0;

        for(int i=0;i<k;i++){
            if(s[i]=='1'){
                one++;
            }
            else if(s[i]=='2'){
                two++;
            }
            else{
                zeros++;
            }
        }

        string ans(n,'+');

        for(int i=0;i<zeros;i++){
            ans[i] = '-';
        }

        for(int i=0;i<one;i++){
            ans[n-i-1] = '-';
        }

        int i = zeros;
        int j = n - one - 1;

        while(i<=j&&two>0){
            ans[i++] = '?';
            ans[j--] = '?';
            two--;
        }
        cout<<ans;


    }
    
    cout<<endl;
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
