#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<string> v(k);

    for (int i = 0; i < k; i++)
    {
        cin>>v[i];
    }
    
    vector<vector<int>> hold(n,vector<int>(26,0));
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            hold[j][(v[i][j] - 'a')]++;
        }
    }
    int sq = sqrt(n);
    int ans = 1e8;
    string anss;
    for(int i=1;i<=sq;i++){
        if(n%i!=0) continue;
        int ct = 0;
        string str;
        int fact = n/i;
        for(int j = 0;j<i;j++){
            vector<int> inter(26,1);
            for(int a = j;a<n;a+=i){
                for(int b=0;b<26;b++){
                    if(inter[b]>0&&hold[a][b]>0) continue;
                    else inter[b] = 0;
                }
            }
            bool check = false;
            for(int a = 0;a<26;a++){
                if(inter[a]>0){
                    str.push_back(a + 'a');
                    check = true;
                    break;
                } 
            }
            
            if(check) ct++;
            else break;
        }
        if(ct==i&&i<ans){
            ans = i;
            anss = str;
        }
        ct = 0;
        str = "";
        for(int j = 0;j<fact;j++){
            vector<int> inter(26,1);
            for(int a = j;a<n;a+=fact){
                for(int b=0;b<26;b++){
                    if(inter[b]>0&&hold[a][b]>0) continue;
                    else inter[b] = 0;
                }
            }
            bool check = false;
            for(int a = 0;a<26;a++){
                if(inter[a]>0){
                    str.push_back(a + 'a');
                    check = true;
                    break;
                } 
            }
            
            if(check) ct++;
            else break;
        }
        if(ct==fact&&fact<ans){
            ans = fact;
            anss = str;
        }
    }
    for(int i=0;i<n;i+=ans) cout<<anss;
    cout<<endl;

}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
