#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n,x;
        cin>>n>>x;
        vector<int> l;
        for(int j=0;j<n;j++){
            int hold;
            cin>>hold;
            l.push_back(hold);
        }
        int h=0;
        sort(l.begin(),l.end());
        int a = 1;
        int m = INT_MAX;
        for(int j=l.size()-1;j>=0;j--){
            m = min(l[j],m);
            if(m*a>=x){
                a=1;
                h++;
                m = l[j];
            }
            else a++;
            // cout<<l[j]<<endl;
        }

        cout<<h<<endl;


    }
}