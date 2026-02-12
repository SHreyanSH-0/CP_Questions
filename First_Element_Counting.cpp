#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int m1 = INT_MAX, m2 = INT_MIN;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        s.insert(v[i]);
        m1 = min(m1,v[i]);
        m2 = max(m2,v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if(v[i]==m1||v[i]==m2){
            cout<<-1<<" ";
        }
        else{
            int hold1 = *(s.upper_bound(v[i]));
            auto it = s.lower_bound(v[i]);
            it--;
            int hold2 = *it;
            int a = (hold1+v[i])/2;
            int b = (hold2+v[i])/2;

            cout<<a - b<<" ";
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
