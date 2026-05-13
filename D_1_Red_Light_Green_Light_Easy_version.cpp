#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> trafficLight(n);
    for (int i = 0; i < n; i++)
    {
        cin>>trafficLight[i];
    }
    vector<int> delay(n);

    for (int i = 0; i < n; i++)
    {
        cin>>delay[i];
    }
    

    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int start;
        cin>>start;

        queue<pair<int,int>> q;

        int idx = lower_bound(trafficLight.begin(),trafficLight.end(),start) - trafficLight.begin();
        if(idx<n){
            q.push({trafficLight[idx] - start,idx});
        }
        else{
            cout<<"YES"<<endl;
            continue;
        }
        vector<int> vis(n,false);
        int dir = 1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int ind = it.second;
            int time = it.first;

            bool isRed = (time - delay[ind] >= 0 && (time - delay[ind])%k == 0);
            if(isRed&&vis[ind]){
                cout<<"NO"<<endl;
                break;
            }

            if(isRed){
                if(dir==1){

                    if(ind-1>=0){
                        vis[ind] = true;
                        q.push({time + abs(trafficLight[ind] - trafficLight[ind-1]),ind-1});
                        dir = -1;
                    }
                    else{
                        cout<<"YES"<<endl;
                    }
                }
                else{
                    vis[ind] = true;
                    q.push({time + abs(trafficLight[ind] - trafficLight[ind+1]),ind+1});
                    dir = 1;
                }
            }
            else{
                if(dir==1){

                    if(ind+1<n){
                        vis[ind] = false;
                        q.push({time + abs(trafficLight[ind] - trafficLight[ind+1]),ind+1});
                    }
                    else{
                        cout<<"YES"<<endl;
                    }
                }
                else{
                    if(ind-1>=0){
                        vis[ind] = false;
                        q.push({time + abs(trafficLight[ind] - trafficLight[ind-1]),ind-1});
                    }
                    else{
                        cout<<"YES"<<endl;
                    }

                }
            }
            
        }

    }
    

    
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
