#include <bits/stdc++.h>
using namespace std;
vector<int> ans(1e7 + 1,-1);
void fun(){
    vector<int> v(1e7+1,1);
    ans[1] = 1;
    for (int i = 2; i <= 1e7; i++)
    {
        for(int j=i;j<=1e7;j+=i){
            v[j] += i;
        }

        if(v[i]<=1e7&&ans[v[i]]==-1) ans[v[i]] = i;
    }
    
}

void solve()
{
    int n;
    cin>>n;
    cout<<ans[n]<<"\n";
}
int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test=1;
cin>>test;
    fun();
    while(test--)
    {
        solve();
    }
    return 0;
}
