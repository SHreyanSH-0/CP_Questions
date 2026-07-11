#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

long long p(long long a,long long b){
    long long ans = 1;
    while(b>0){
        if(b%2==1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b/=2;
    }
    return ans;
}

int inv(int a){
    return p(a,mod-2);
}

vector<int> f(){
    vector<int> spf(5e5+1);
    for (int i = 0; i <= 5e5; i++)
    {
        spf[i] = i;
    }
 
    for (int i = 2; i <= 5e5; i++)
    {
        for(int j=i;j<=5e5;j+=i){
            if(spf[j]==j)
            spf[j] = spf[i];
        }
    }
    return spf;
}
vector<int> spf;

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
 
    vector<int> ct(1e5+1,0);
 
    vector<int> spf(1e5+1);
    for (int i = 0; i <= 1e5; i++)
    {
        spf[i] = i;
    }
 
    for (int i = 2; i <= 1e5; i++)
    {
        for(int j=i;j<=1e5;j+=i){
            if(spf[j]==j)
            spf[j] = spf[i];
        }
    }
    
    
 
    for (int i = 0; i < n; i++)
    {
        int hold = v[i];
        int l = sqrt(hold);
        for (int j = 1; j <= l; j++)
        {
            if(hold%j==0){
                ct[j]++;
                if(hold/j != j)
                ct[hold/j]++;
            }
        }
    }
 
    int ans = 1;
 
    vector<bool> can(1e5+1,false);
    map<int, vector<int>> map;
    for (int i = 2; i <= 1e5; i++)
    {
        for(int j=i;j<=1e5;j+=i){
            if(ct[j]>0 && can[j]==false){
                can[j] = true;
                map[i].push_back(j);
            }
        }
    }
    unordered_map<int,int> count;
    int multi = 1;
    for(auto&[num, vec]:map){
        int sum = 1;
        // cout<<num<<"->";
        for (int i = 0; i < vec.size(); i++)
        {
            // cout<<vec[i]<<" ";
            sum += ct[vec[i]];
        }
        // cout<<endl;
        count[num] = sum;
        multi = (multi * sum)%mod;
    }
    for(auto&[num, vec]:map){
        multi = 1;
        for(auto&[x,y]:count){
            if(x>num) multi = (multi * y)%mod;
        }
        // cout<<multi<<endl;
        for (int j = 0; j < vec.size(); j++)
        {
           int hold = vec[j];
           int l = sqrt(hold);
           int mul = 1;
           int a = ct[vec[j]];
           
        //    for (int i = 2; i <= l; i++)
        //    {
        //         if(hold%i==0){
        //             if(i>num){
        //                 mul = (mul*count[i]);
        //                 count[i]--;
        //                 ct[i]--;
        //             } 
        //             while(hold%i==0) hold/=i;
        //         }
        //     }
 
            while(hold>1){
                int x = spf[hold];
                while(hold%x==0) hold/=x;
                if(x>num){
                    mul = (mul*count[x]);
                    count[x]--;
                    ct[x]--;
                }
            }
            
            // if(hold>num){
            //     mul = (mul*count[hold])%mod;
            //     count[hold]--;
            //     ct[hold]--;
            // }
        //    cout<<mul<<endl;
        //    cout<<num<<" "<<vec[j]<<" "<<((multi * inv(mul))* a)%mod<<" "<<hold<<endl;
            
            ans += ((multi * inv(mul))* ct[vec[j]])%mod;
            ans %= mod;
        }
        
    }
    // 1 3 4 5 6 9
    cout<<ans%mod<<endl;
}


signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
    spf = f();
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
