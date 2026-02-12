#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int x=0;x<t;x++){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        int m = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
            m = max(m,v[i]);
        }
 
        int low = 1, high = m;
        while (low<=high){
            
        }
        
    }
}