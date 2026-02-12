#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,l,r,s;
    cin>>n>>l>>r>>s;
    
    int x = (r-l+1);

    int lowerLimit = (x*(x+1))/2;
    int upperLimit = (x*(2*n-x+1))/2;

    vector<int> ans(n+1,0);
    if(s<lowerLimit||s>upperLimit){
        cout<<-1<<endl;
        return;
    }
    else{

        int left = (s - lowerLimit)%x;
        int toGive = (s - lowerLimit)/x;
        int start = 1;
        for(int i=l;i<=r;i++){
            ans[i] = start + toGive;
            start++;
        }

        int i = r;
        while(left>0){
            ans[i--]++;
            left--;
        }

        set<int> used;
        
        for (int i = 1; i <=n; i++)
        {
            used.insert(i);
        }
        for (int i = l; i <=r; i++)
        {
            used.erase(ans[i]);
        }
        
        for(int i = 1;i<l;i++){
            ans[i] = *used.begin();
            used.erase(*used.begin());
        }
        for (int i = r+1; i <= n; i++)
        {
            ans[i] = *used.begin();
            used.erase(*used.begin());
        }
    }

    

    
    for (int i = 1; i <= n; i++)
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
