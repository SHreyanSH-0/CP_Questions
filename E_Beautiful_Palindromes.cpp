#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        s.insert(v[i]);
    }

    if(1){
        int start = v[0];
        for (int i = 1; i <=n; i++)
        {
            if(s.find(i)==s.end()) {
                start = i;
                break;
            }
        }
        
        cout<<start<<" ";

        if(k>1){         
            int hold = start+1; 
            int hold2;  
            for (int i = 1; i < k;hold++)
            {
                if(hold>n) hold = 1;
                if(hold==v[n-1]&&i==1) continue;
                cout<<hold<<" ";
                break;
                i++;
            }

            for (int i = 3; i <= k; i++)
            {
                if(i%3==0){
                    cout<<v[n-1]<<" "; 
                }
                else if(i%3==1){
                    cout<<start<<" "; 
                    
                }
                else{
                    cout<<hold<<" "; 
                }

            }
            
        }
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
