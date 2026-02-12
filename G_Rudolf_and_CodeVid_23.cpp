#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    string symp;
    cin>>symp;
    vector<vector<int>> v(m);

    for(int i = 0;i<m;i++){
        int d;
        string c,s;
        cin>>d>>c>>s;
        int pow = 1;
        int hold1 = 0;
        int hold2 = 0;
        for(int i=c.size()-1;i>=0;i--){
            if(c[i]=='1'){
                hold1+=pow;
            }
            pow*=2;
        }
        pow = 1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                hold2+=pow;
            }
            pow*=2;
        }
        v[i] = {d,hold1,hold2};
    }

    int pow = 1;
    int hold = 0;
    for(int i=symp.size()-1;i>=0;i--){
        if(symp[i]=='1'){
            hold+=pow;
        }
        pow*=2;
    }

    vector<int> dist(1024,INT_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    q.push({0,hold});

    while(!q.empty()){
        auto it = q.top();
        q.pop();
        
        int days = it.first;
        int node = it.second;
        if(days > dist[node]) continue;
        
        if(node==0){
            cout<<days<<endl;
            return;
        }

        for(int i = 0;i<m;i++){
            int h1 = node;
            int ans = node;
            int h2 = v[i][1];
            int p = 1;
            while(h1>0){
                if(h1%2==1&&h2%2==1){
                    ans -= p;
                }
                p*=2;
                h1/=2;
                h2/=2;
            }

            ans = (ans|v[i][2]);

            if(dist[ans]>days + v[i][0]){
                dist[ans] = days + v[i][0];
                q.push({dist[ans],ans});
            }
        }
    }
    cout<<-1<<endl;
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
