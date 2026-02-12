#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<long long> v(n);

    int check = 0;

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(i>0&&v[i]>=v[i-1]) check++;
    }

    if(check==n-1){
        cout<<0<<endl;
    }
    else if(v[n-2]<=v[n-1]){

        int j;
        bool c = true;
        for (j = n-1; j >0; j--)
        {
            if(v[j]<v[j-1]){
                c = false;
                break;
            }

            if(v[j]>=v[j-1]&&v[j]>=0){
                break;
            }
        }
        

        if(c){
            cout<<j-1<<endl;
            for (int i=0;i<j-1;i++)
            {
                cout<<i+1<<" "<<n-1<<" "<<n<<endl;
            }
        }
        else cout<<-1<<endl;
        
    }
    else{
        cout<<-1<<endl;
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
