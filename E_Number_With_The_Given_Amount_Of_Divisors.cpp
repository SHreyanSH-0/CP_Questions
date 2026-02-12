#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
vector<int> prime;
int fun(int num,int n){
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if(ans>=1e18/num) return 1e18;
        ans *= num;
    }
    return ans;
}
void solve()
{
    int n ;
    cin>>n;
    vector<int> v;
    prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
53, 59, 61};
    int sum = 0;
    for(int i=2;n>1;i++){
        while(n%i==0){
            v.push_back(i);
            n/=i;
            sum+=i;
        }
    }
    int ans = 1;
    vector<int> used(v.size(),0);
    for(int i=v.size()-1;i>=0;i--){
        int mul = 1e18;
        int ind;
        for (int j = 0; j < v.size(); j++)
        {
            int l = (used[j]+1)*v[i]-1;
            
            int h = fun(prime[j],l)/fun(prime[j],used[j]);

            if(h<mul){
                mul = h;
                ind = j;
            }

        }
        
        ans *= mul;
        used[ind] = (used[ind] + 1)*v[i] - 1;
    }
    

    cout<<ans;

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
