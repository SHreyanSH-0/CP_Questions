#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    int two = 2;
    int three = 3;
    vector<int> ans,hold;
    
    for(int i=1;i<=n;i++){
        if(i%2!=0&&i%3!=0){
            hold.push_back(i);
        }
    }    
    int j = 0;
    while(ans.size()<n)
    {   
        if(j<hold.size())
        ans.push_back(hold[j++]);
        if(two<=n){
            ans.push_back(two);
            two+=2;
            if(two<=n){
                ans.push_back(two);
                two+=2;
            }
        }
        else{
            ans.push_back(three);
            three+=6;
            if(three<=n){
                ans.push_back(three);
                three+=6;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
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
