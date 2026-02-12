#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> v(n), hold;
        set<int> s;
        int m = INT_MIN;
        for (int j = 0; j < n; j++){
           cin>> v[j];
           s.insert(v[j]);
           m = max(hold[j],m);
        }

        for(auto it : s){
            hold.push_back(it);
            cout<<it<<" ";
        }


        int count = 0;
        int ans = 0;
        int k = n-1;
    
        for (int j = 0; j < n; j++){
            if(v[j]==m&&(j==n-1||v[j+1]!=m)){
                count++;
            }
        }
        cout<<count<<endl;
        

         
    }
}