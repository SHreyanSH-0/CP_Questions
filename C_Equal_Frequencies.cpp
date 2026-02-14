#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int ans = INT_MAX;
    string ansStr;
    vector<int> check(26,0);
    vector<pair<int,char>> v;
    for(auto &it:s) check[it-'a']++;
    for(int i=0;i<26;i++) v.push_back({check[i],i+'a'});
    sort(v.rbegin(),v.rend());
    for (int i = 1; i <= min(n,26LL); i++)
    {
        if(n%i!=0) continue;
        set<char> set;
        for(int j=0;j<i;j++) set.insert(v[j].second);
        
        string hold = s;
        vector<int> count(check.begin(),check.end());
        int freq = n/i;
        int ct = 0;
        for(int j=0;j<n;j++){
            if(set.find(s[j])==set.end()){
                for(auto&it:set){
                    if(count[it-'a']<freq){
                        count[it-'a']++;
                        count[s[j]-'a']--;
                        ct++;
                        hold[j] = it;
                        break;
                    }
                }
                continue;
            }
            if(count[s[j]-'a']>freq){
                for(auto&it:set){
                    if(count[it-'a']<freq){
                        count[it-'a']++;
                        count[s[j]-'a']--;
                        ct++;
                        hold[j] = it;
                        break;
                    }
                }
            }
        }
        if(ans>ct){
            ans = ct;
            ansStr = hold;
        }
    }
    cout<<ans<<endl<<ansStr<<endl;
    
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
