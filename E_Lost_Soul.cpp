#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    
    set<int> s1,s2;

    int x = 0;

    for(int i=n-1;i>=0;i--){
        
        if(b[i] == a[i]) {
            cout<<i+1<<endl;
            return;
        }

        
        if(x%2==0){
            if(s2.find(a[i])!=s2.end()||s1.find(b[i])!=s1.end()){
                cout<<i+1<<endl;
                return;
            }
            else if(i>0&&(s1.find(b[i-1])!=s1.end()||s2.find(a[i-1])!=s2.end())){
                cout<<i<<endl;
                return;
            }
            s1.insert(a[i]);
            s2.insert(b[i]);
        }
        else{
            if(s2.find(b[i])!=s2.end()||s1.find(a[i])!=s1.end()){
                cout<<i+1<<endl;
                return;
            }
            else if(i>0&&(s1.find(a[i-1])!=s1.end()||s2.find(b[i-1])!=s2.end())){
                cout<<i<<endl;
                return;
            }
            s1.insert(b[i]);
            s2.insert(a[i]);
        }

        x++;
    }

    cout<<0<<endl;
    

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
