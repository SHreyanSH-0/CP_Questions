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
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }

    vector<int> b(n,1e15);
    b[0] = c[0];
    int end = 0;
    for (int i = 1; i < n; i++)
    {
        if(c[i] != c[i-1]){
            end = i;
            b[i] = c[i];
        }
        else{
            if(s[i]=='1'&&b[i-1]<1e15){
                b[i] = b[i-1] + a[i];
            }
        }
    }

    int prev = 0;
    stack<int> temp;
    int hold = 0;
    for (int i = 1; i < n; i++)
    {
        if(s[i]=='0')
        temp.push(i);
        else hold+=a[i];


        if(b[i]<1e15){
            if(prev!=-1){
                int sum = b[i] - b[prev];
                sum -= hold;   
                sum = sum + 1e12;
                int idx=-1;
                while (!temp.empty())
                {
                    a[temp.top()] = sum;
                    sum = 0;
                    s[temp.top()] = '1';
                    idx = temp.top();
                    temp.pop();
                }
                if(idx!=-1)
                a[idx] -= 1e12;
            }
            else{
                int sum = b[i];
                sum -= hold;
                sum = sum + 1e12;
                int idx = -1;
                while (!temp.empty())
                {
                    a[temp.top()] = sum;
                    sum = 0;
                    s[temp.top()] = '1';
                    temp.pop();
                }
                if(idx!=-1)
                a[idx] -= 1e12;
                
            }
            prev = i;
            hold = 0;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1') {
            continue;
        }
        if(i==0) a[i] = b[i];
        else a[i] = b[i] - b[i-1];
    }
    
    for (int i = end+1; i < n; i++)
    {
        if(s[i]=='0')
        a[i] = -1e12;
    } 

    int maxi = -1e18;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {   
        sum += a[i];
        maxi = max(maxi,sum);
        if(maxi!=c[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    
    cout<<"YES"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    

    
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