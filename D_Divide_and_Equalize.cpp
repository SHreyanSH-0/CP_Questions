#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    unordered_map<int,int> map;

    for (int i = 0; i < n; i++)
    {
        int val = v[i];
        int l = sqrt(val);
        
        for(int j=2;j<=l;){
            if(val%j==0){
                map[j]++;
                val/=j;
            }
            else j++;
        }
        if(val>1) map[val]++;
    }
    int check = 1;

    for (auto i : map)
    {
        if(i.second%n!=0) {
            check = 0;
            break;
        }
    }

    if(check ) cout<<"YES\n";
    else cout<<"NO\n";
    
    

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
