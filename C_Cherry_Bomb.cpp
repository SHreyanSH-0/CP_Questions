#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin >> n>> k;
        int ans = 1;
        vector<int> a(n),b(n);
        for (int j = 0; j < n; j++)
        {
            cin>>a[j];
        }

        for (int j = 0; j < n; j++)
        {
            cin>>b[j];
        }
        int x = -1;
        int minele = INT_MAX,maxele = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            minele = min(minele,a[j]);
            maxele = max(maxele,a[j]);
            if(b[j]>=0){
                if(x!=-1&&x!=a[j]+b[j]){
                    ans = 0;
                    break;
                }
                else
                x = a[j]+b[j];
            }
        }

        if(ans==0||minele+k<x||(maxele>x&&x!=-1)){
            cout<<0<<endl;
        }
        else if(x==-1){
            cout<<minele+k-maxele+1<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }
}