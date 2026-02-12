#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    if(s=="first"){
        int n;
        cin>>n;
        string ans;
        for (int i = 0; i < n; i++)
        {
            int hold;
            cin>>hold;
            int j = 0;
            while(j<7||hold>0){
                ans.push_back(hold%26 + 'a');
                hold/=26;
                j++;
            }
        }

        cout<<ans;        
    }
    else{
        string a;
        cin>>a;
        int n = a.size()/7;
        cout<<n<<endl;
        for(int i=0;i<a.size();i+=7){
            int hold = 0;
            int pow = 1;
            for (int j = 0; j < 7; j++)
            {
                hold = hold + (a[i+j] - 'a')*pow;
                pow*=10;
            }
            cout<<hold<<" ";
            
        }
        
    }
}
signed main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
