#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int sum = 0;
        int hold = n;
        for (int j = 1; j <= n; j++,hold--)
        {
            sum+=abs(hold-j);
        }
        cout<<sum/2+1<<endl;
    }
}