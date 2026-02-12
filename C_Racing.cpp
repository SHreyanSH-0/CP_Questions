#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        vector<vector<int>> obs;
        int n;
        cin>>n;
        vector<int> cou(n);
        for (int j = 0; j < n; j++)
        {
            cin>>cou[j];
        }
        
        for (int j = 0; j < n; j++)
        {
            int l,r;
            cin>>l>>r;
            obs.push_back({l,r});
        }
        
        int h = 0;
        
        int ans = 1;
        for (int j = 0; j < n; j++)
        {
            if(h>=obs[j][0]&&h<=obs[j][1]){
                if(cou[j]==-1){
                    cou[j] = 0;
                }
            }
            else{
                if(cou[j]==-1&&(h+1>=obs[j][0]&&h+1<=obs[j][1])){
                    cou[j] = 1;
                    h++;
                }
            }
        }
        
        for (int j = 0; j < n; j++)
        {
            cout<<cou[j]<<" ";
        }
        cout<<endl;
        
        
    }
}