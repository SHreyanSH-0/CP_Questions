#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    if(n==2){
        if(abs(v[0]-v[1])<=1) cout<<0<<endl;
        else cout<<-1<<endl;
    }
    else{
        int ans = INT_MAX;
        for (int i = 0; i < n-1; i++)
        {
            if(abs(v[i]-v[i+1])<=1){
                cout<<0<<endl;
                return;
            }
        }
        
        for (int i = 0; i < n-1; i++)
        {
            if(v[i+1]<=v[i]){
                int a = v[i],b = v[i+1];
                
                for (int j = i-1; j >=0; j--)
                {
                    if(v[j]>=min(a,b)&&v[j]<=max(a,b)){
                        ans = min(ans,abs(i-j));
                        break;
                    }
                }
                
                for (int j = i-1; j >=0; j--)
                {
                    if(v[j]<=v[i+1]){
                        ans = min(ans,abs(i-j));
                        break;
                    }
                }

                for (int j = i+2; j <n; j++)
                {
                    if(v[j]>=min(a,b)&&v[j]<=max(a,b)){
                        ans = min(ans,abs(i-j)-1);
                        break;
                    }
                }
                for (int j = i+2; j <n; j++)
                {
                    if(v[j]>=v[i]){
                        ans = min(ans,abs(i-j)-1);
                        break;
                    }
                }

            }
        }

        if(ans!=INT_MAX){
            cout<<ans<<endl;
        }
        else cout<<-1<<endl;

        
        
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
